
/* $PAGE */
/* $TITLE=adjust_clock_brightness() */
/* --------------------------------------------------------------------- *\
    Read ambient light level from Pico's analog-to-digital gpio, where
                   a photo resistor has been connected
            (inside the Green Clock, above the USB connector)
         and then, adjust clock display brightness according to
     average ambient light level for the last 60 seconds (hysteresis).
    NOTE: Clock must be setup for auto-brightness. Refer to User Guide
\* --------------------------------------------------------------------- */
#include "pico-green-clock.h"
#include "configuration.h"
#include "typedefs.h"
#include "debug.h"
void adjust_clock_brightness(void)
{
UINT16 AverageLightLevel ;       // relative ambient light value (for clock display auto-brightness feature). 
extern UINT64 DebugBitMask;                           // bitmask of code sections to be debugged through UART (see definitions of DEBUG sections above).
extern struct flash_config FlashConfig;
UCHAR String[128];

    UINT Loop1UInt;
    static UINT NextCell = 0;  // point to next slot of circular buffer to be read.

    UINT16 AverageLevel;
    UINT16 DutyCycle;

    static UINT16 AmbientLightMSecCounter;
    static UINT16 LightLevel[MAX_LIGHT_SLOTS] = { 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550 };  // assume average ambient light level on entry.

    int32_t TempLevel;

    static UINT64 CumulativeLightLevel;


    /* If the clock has been setup for auto-brightness, get ambient light level from Pico's analog-to-digital converter.
       (if clock is not in auto-brightness mode, an "average light level value" of 550 will be kept as default until auto-brightness is selected). */
    if (FlashConfig.FlagAutoBrightness == FLAG_ON)
    {
        /* Cumulate 5000 readings of the ambient light value (5 seconds of readings every msec.). */
        ++AmbientLightMSecCounter;
        CumulativeLightLevel += adc_read_light();


        /* Check if 5000 milliseconds (5 seconds) have elapsed. */
        if (AmbientLightMSecCounter >= 5000)
        {
            /* Reset the 5000 milliseconds counter. */
            AmbientLightMSecCounter = 0;

            /* Calculate the average ambient light level for the last five seconds (5000 milliseconds). */
            LightLevel[NextCell++] = CumulativeLightLevel / 5000;  // average light level for the last 5 seconds.
            if (NextCell >= MAX_LIGHT_SLOTS) NextCell = 0;         // replace the slot for the last 5-seconds period and when out-of-bound, revert to zero.
            CumulativeLightLevel = 0;


            /* Calculate average ambient light level for the last minute, based on the "MAX_LIGHT_SLOTS" number of "5-seconds" light level slots. */
            for (Loop1UInt = 0; Loop1UInt < MAX_LIGHT_SLOTS; ++Loop1UInt)
                CumulativeLightLevel += LightLevel[Loop1UInt];


            AverageLightLevel = (CumulativeLightLevel / MAX_LIGHT_SLOTS);  // average light level for the last "MAX_LIGHT_SLOTS" number of "5-seconds" light level slots.
            CumulativeLightLevel = 0;  // get ready to cumulate the next 5000 milliseconds.


            /* Update current clock display brightness, based on average ambient light level for the last 2 minutes (hysteresis).
               Ambient light level goes from around 200 (very dark) to 1500 (very bright). */
               /** 20240819 BB
               Observation:
               Light level from 210 (sensor covert)
               to 220...250 (clock casing closed, normal livingroom light)
               to 790 (clock casing closed, placed below lamp)
               desired duty cycle: 100 (light) through 40 (livingroom) to 10 (dark)
               Mapping:  Average Level   Duty Cycle
                         790             100
                         250             40
                         210             10
               Linear Regression:
                         lighter: Avl 790...250, Dc=100...40: Dc=Avl*0,1098+13,255
                         lower:   Avl 250...210, Dc= 40... 10: Dc=Avl*0,7676-151,206
               **/
            AverageLevel = AverageLightLevel;
            /** original
                  if (AverageLightLevel < 225) AverageLevel = 225;
                  if (AverageLightLevel > 525) AverageLevel = 525;
                  DutyCycle = (UINT16)((AverageLevel - 225) / 3.0);
            original **/
            /**new**/
            if (AverageLightLevel < 210) AverageLevel = 210;
            if (AverageLightLevel > 790) AverageLevel = 790;
            if (AverageLevel > 250)
                DutyCycle = (UINT16)((double)AverageLevel * 0.1098 + 13.255);
            else
                DutyCycle = (UINT16)((double)AverageLevel * 0.7676 - 151.206);
            pwm_set_duty_cycle(DutyCycle);


            if (DebugBitMask & DEBUG_BRIGHTNESS)
            {
                uart_send(__LINE__, "Instant level: %4u   AverageLevel: %4u\r", adc_read_light(), AverageLevel);
                uart_send(__LINE__, "Duty cycle: %3u\r\r", DutyCycle);
            }
        }
    }

    return;
}


