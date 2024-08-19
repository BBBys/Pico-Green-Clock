#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdint.h>
typedef unsigned int  UINT;   // processor-optimized.
typedef uint8_t       UINT8;
typedef uint16_t      UINT16;
typedef uint32_t      UINT32;
typedef uint64_t      UINT64;
typedef unsigned char UCHAR;


/* Alarm definitions. */
struct alarm
{
    UINT8 FlagStatus;
    UINT8 Second;
    UINT8 Minute;
    UINT8 Hour;
    UINT8 Day;
    UCHAR Text[40];
};



/* Structure containing the Green Clock configuration being saved to flash memory.
   Those variables will be restored after a reboot and / or power failure. */
   /* IMPORTANT: Version must always be the first element of the structure and
                 CRC16   must always be the  last element of the structure. */
struct flash_config
{
    UCHAR  Version[6];          // firmware version number (format: "06.00" - including end-of-string).
    UINT8  CurrentYearCentile;  // assume we are in years 20xx on power-up but is adjusted when configuration is read (will your clock live long enough for a "21" ?!).
    UINT8  Language;            // language used for data display (including date scrolling).
    UCHAR  DSTCountry;  // specifies how to handle the daylight saving time (see User Guide and / or clock options above).
    UINT8  TemperatureUnit;     // CELSIUS or FAHRENHEIT default value (see clock options above).
    UINT8  TimeDisplayMode;     // H24 or H12 default value (see clock options above).
    UINT8  ChimeMode;           // chime mode (Off / On / Day).
    UINT8  ChimeTimeOn;         // hourly chime will begin at this hour.
    UINT8  ChimeTimeOff;        // hourly chime will stop after this hour.
    UINT8  NightLightMode;      // night light mode (On / Off / Auto / Night).
    UINT8  NightLightTimeOn;    // default night light time On.
    UINT8  NightLightTimeOff;   // default night light time Off.
    UINT8  FlagAutoBrightness;  // flag indicating we are in "Auto Brightness" mode.
    UINT8  FlagKeyclick;        // flag for keyclick ("button-press" tone)
    UINT8  FlagScrollEnable;    // flag indicating the clock will scroll the date and temperature at regular intervals on the display.
    UINT8  FlagSummerTime;      // flag indicating the current status (On or Off) of Daylight Saving Time / Summer Time.
    int8_t Timezone;            // (in hours) value to add to UTC time (Universal Time Coordinate) to get the local time.
    UINT8  Reserved1[48];       // reserved for future use.
    struct alarm Alarm[9];      // alarms 0 to 8 parameters (numbered 1 to 9 for clock users). Day is a bit mask.
    UCHAR  SSID[40];            // SSID for Wi-Fi network. Note: SSID begins at position 5 of the variable string, so that a "footprint" can be confirmed prior to writing to flash.
    UCHAR  Password[70];        // password for Wi-Fi network. Note: password begins at position 5 of the variable string, for the same reason as SSID above.
    UCHAR  Reserved2[48];       // reserved for future use.
    UINT16 Crc16;               // crc16 of all data above to validate configuration.
};// FlashConfig;

#endif
