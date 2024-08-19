
/* $TITLE=Clock configuration or options. */
/* $PAGE */
/* ================================================================== *\
              ===== CLOCK CONFIGURATION OR OPTIONS =====
     SOME OF THESE ITEMS ARE ADJUSTABLE AT RUNTIME, OTHERS ARE NOT.
     NOTE: Structure "CalendarEvent" should also be initialized
             according to user needs. It is in the file:
                     "CalendarEventsGeneric.cpp".
\* ================================================================== */
/* Firmware version. */
#define FIRMWARE_VERSION "9.02"  ///

/* Select the language for data display. */
#define DEFAULT_LANGUAGE GERMAN // choices for now are FRENCH, ENGLISH, GERMAN, and SPANISH.

/* While in development mode, we may want to disable NTP update, for example while testing Summer Time handling algorithm. */
// #define NTP_ENABLE  /// WARNING: This #define is not supported for now. Use "#define PICO_W" below instead to enable NTP for now.
#define NETWORK_NAME     "MyNetworkName"  /// for those with a development environment, you can enter your SSID and password below, run the Firmware until the
#define NETWORK_PASSWORD "MyPassword"     /// first date scrolling (credentials will be saved to flash), then erase the credentials and put comment on both lines.

/* If a Pico W is used, librairies for Wi-Fi and NTP synchronization will be merged in the executable. If PICO_W is not defined, NTP is automatically disabled. */
#define PICO_W  ///

/* Flag to handle automatically the daylight saving time. List of countries are given in the User Guide. */
#define DST_COUNTRY DST_EUROPE
#define TIMEZONE    1

/* Release or Developer Version: Make selective choices or options. */
//#define RELEASE_VERSION  ///erfolgt in cmake-List funktioniert nicht



/* ----------------------------------------------------------------------------------------------------------------------- *\
                                             Setup specific to RELEASE version.
\* ----------------------------------------------------------------------------------------------------------------------- */
#ifdef RELEASE_VERSION
#warning Built as RELEASE_VERSION

/* Specify the filename of calendar events to merge with this version of firmware. */
#define CALENDAR_FILENAME "CalendarEventsGeneric.cpp"

/* Specify the filename of reminders to merge with this version of firmware. */
#define REMINDER_FILENAME "RemindersGeneric.cpp"
#endif  // RELEASE_VERSION
/* ----------------------------------------------------------------------------------------------------------------------- *\
                                           End of setup specific to RELEASE version.
\* ----------------------------------------------------------------------------------------------------------------------- */





/* ----------------------------------------------------------------------------------------------------------------------- *\
                                               Setup specific to DEVELOPER version.
   NOTE: Developer version requires a USB CDC communication to start. Refer to User Guide for details.
\* ----------------------------------------------------------------------------------------------------------------------- */
#ifndef RELEASE_VERSION
#define DEVELOPER_VERSION
#warning Built as DEVELOPER_VERSION

/* Specify the filename of calendar events to merge with this version of firmware. */
//#define CALENDAR_FILENAME "CalendarEventsAndre.cpp"

/* Specify the filename of calendar events to merge with this version of firmware. */
//#define REMINDER_FILENAME "RemindersAndre.cpp"

/* Specify the filename of calendar events to merge with this version of firmware. */
#define CALENDAR_FILENAME "CalendarEventsGeneric.cpp"

/* Specify the filename of reminders to merge with this version of firmware. */
#define REMINDER_FILENAME "RemindersGeneric.cpp"

/* Conditional compile to allow a quicker power-up sequence by-passing some device tests. */
#define QUICK_START  ///
#ifdef QUICK_START
#warning Built with QUICK_START
#endif  // QUICK_START

/* If SOUND_DISABLED is commented out below, it allows turning Off <<< ABSOLUTELY ALL SOUNDS >>> from the Green Clock.
   (For example, during development phase, if your wife is sleeping while you work late in the night as was my case - smile). */
   // #define SOUND_DISABLED  ///
#ifdef SOUND_DISABLED
    #warning Built with SOUND DISABLED
#endif  // SOUND_DISABLED

    /* Flag to include test code in the executable (conditional compile). Tests can be run before falling in normal clock ("time display") mode.
       Keeping the comment sign on the #define below will exclude test code and make the executable smaller. */
#define TEST_CODE

       /* Loop at the beginning of the code until a USB CDC connection has been established. Quick beeps will be heard during waiting so that user
          is aware of what's going on. */
#define USB_CONNECTION  ///
#ifdef USB_CONNECTION
    #warning Built with USB_CONNECTION
#endif  // USB_CONNECTION

    /* ---------------------------------------------------------------------------------- *\
                              Options that can be installed by user.
    \* ---------------------------------------------------------------------------------- */
    /* Support for an optional passive buzzer. This buzzer must be provided by user and is not included with the Green Clock.
       It allows variable frequency sounds on the clock.
       If you did install one, cut this block and paste is outside of the "#ifdef DEVELOPER_VERSION" and "#endif" to enable the "#define PASSIVE_PIEZO_SUPPORT". */
       // #define PASSIVE_PIEZO_SUPPORT  /// if a passive buzzer has been installed by user.
#ifdef PASSIVE_PIEZO_SUPPORT
    #warning Built with PASSIVE_PIEZO support
#endif  // PASSIVE_PIEZO_SUPPORT


    /* Support of an optional (external) temperature and humidity sensor (DHT22) or temperature, humidity and atmospheric pressure sensor (BME280)
       to read and display those parameters. The sensors must be bought and installed by user. They are not included with the Pico Green Clock.
       If you did install one, cut this block and paste it outside of the "#ifdef DEVELOPER_VERSION" and "#endif" to enable the "#define DHT_SUPPORT and / or
       "#define BME280_SUPPORT". */
       //#define DHT_SUPPORT  /// if a DHT22 temperature and humidity sensor has been installed by user.
#ifdef DHT_SUPPORT
    #warning Built with DHT22 support
#endif  // DHT_SUPPORT

    //#define BME280_SUPPORT  /// if a BME280 temperature, humidity and barometric pressure sensor has been installed by user.
#ifdef BME280_SUPPORT
    #warning Built with BME280 support
#endif  // BME280_SUPPORT


    /* Support of an optional remote control to interact with the clock remotely, for example when the clock is installed
       too high and is out of reach. There is no remote control provided with the clock. It must be bought by the user.
       Current support is for a Memorex remote control, model MCR 5221 that I had readily available. If another brand of
       remote control is to be used, user will have to decode its protocol and implement it in the Green Clock firmware.
       (a file similar to "memorex.cpp" must be created to support the new remote control).
       If you did install an infrared sensor, cut this block and paste it outside of the "#ifdef DEVELOPER_VERSION" and "#endif" to enable the "#define IR_SUPPORT".
       You also need to replace the default "REMOTE_FILENAME" by the filename you created containing the infrared timing / codes corresponding to your remote control.
       You may want to check the Pico-Remote-Analyzer utility in one of my repositories. */
       //#define IR_SUPPORT // if an infrared sensor (VS1838B-type) has been installed by the user and IR protocol of the remote control has been analyzed and implemented.

       /* Specify the file containing the remote control protocol to be used. */
#define REMOTE_FILENAME "memorex.cpp"

/* Silence period request unit (in minutes). Needs remote control. */
#define SILENCE_PERIOD_UNIT 30
#ifdef IR_SUPPORT
#warning Built with INFRARED support
#endif  // IR_SUPPORT
#endif  // DEVELOPER_VERSION

/* ----------------------------------------------------------------------------------------------------------------------- *\
                                            End of setup specific to DEVELOPER version
\* ----------------------------------------------------------------------------------------------------------------------- */



/* Determine if date scrolling will be enable by default when the clock starts. */
#define SCROLL_DEFAULT FLAG_ON  // choices are FLAG_ON / FLAG_OFF

/* Scroll one dot to the left every such milliseconds (80 is a good start point. lower = faster). */
#define SCROLL_DOT_TIME 66      // this is a UINT8 (must be between 0 and 255).

/* Date, temperature and other options will scroll at this frequency
   (in minutes - we must leave enough time for the previous scroll to complete). */
#define SCROLL_PERIOD_MINUTE 15

   /* Default temperature unit to display on the clock. */
#define TEMPERATURE_DEFAULT CELSIUS  // choices are CELSIUS and FAHRENHEIT.

/* Time will be displayed in 24-hours format by default. */
#define TIME_DISPLAY_DEFAULT H24     // choices are H12 and H24.

/* Exit setup mode after this period of inactivity (in seconds). (for "clock setup", "alarm setup" or "timer setup"). */
#define TIME_OUT_PERIOD 20

/* Maximum number of seconds an alarm will ring. It will be automatically shut Off after this period in seconds
   if user has not pressed yet the "Set" (top) button. */
#define MAX_ALARM_RING_TIME 3600 // (in seconds) alarm will be automatically shut Off after ringing for one hour (3600 seconds).

   /* Night light default values. "AUTO" is based on ambient light reading to turn night light On or Off. */
#define NIGHT_LIGHT_DEFAULT   NIGHT_LIGHT_AUTO  // choices are NIGHT_LIGHT_OFF / NIGHT_LIGHT_ON / NIGHT_LIGHT_NIGHT / NIGHT_LIGHT_AUTO
#define NIGHT_LIGHT_TIME_ON   23                // if "NIGHT_LIGHT_NIGHT", LEDs will turn On  at this time (in the evening).
#define NIGHT_LIGHT_TIME_OFF   7                // if "NIGHT_LIGHT_NIGHT", LEDs will turn Off at this time (in the morning).

/* Hourly chime default values. */
#define CHIME_DEFAULT  CHIME_DAY         // choices are CHIME_OFF / CHIME_ON / CHIME_DAY
#define CHIME_TIME_ON          9         // if "CHIME_DAY", "hourly chime" and "calendar event" will sound beginning at this time (in the morning).
#define CHIME_TIME_OFF        21         // if "CHIME_DAY", "hourly chime" and "calendar event" will sound for the last time at this time (in the evening).
#define CHIME_HALF_HOUR  FLAG_ON         // if "FLAG_ON", will sound a "double-beep" on half-hour (every xxh30), compliant to chime settings above.
#define CHIME_HOUR_COUNT FLAG_OFF        // if "FLAG_ON", hourly chime will beep a number of times equivalent to the hour value in 12-hour format.
#define CHIME_HOUR_COUNT_BEEP_DURATION 300  // duration of "hour count" beeps (in msec) when flag above is On.
/* NOTE: See also revision history above (or User guide) about "night time workers" support for hourly chime. */

/* For active buzzer integrated in Pico Green Clock. Number of "tones" for each "sound pack" (first level of repetition). */
#define TONE_CHIME_REPEAT1     2
#define TONE_EVENT_REPEAT1     5
#define TONE_KEYCLICK_REPEAT1  1
#define TONE_TIMER_REPEAT1     4

/* For active buzzer integrated in Pico Green Clock.
   Number of times the "sound pack" above will repeat itself for each tone type (second level of repetition).
   for example, if TONE_CHIME_REPEAT_1 is set to 3 and TONE_CHIME_REPEAT_2 is set to 2, we will hear:
   beep-beep-beep..........beep-beep-beep (three beeps, twice). */
#define TONE_CHIME_REPEAT2     3
#define TONE_EVENT_REPEAT2     3
#define TONE_KEYCLICK_REPEAT2  1
#define TONE_TIMER_REPEAT2     2

   /* For active buzzer integrated in Pico Green Clock.
      Time duration for different tone types (in milliseconds). This is the time of each sound inside one "sound pack".
      will be rounded-up by the clock to the next 50 milliseconds multiple.
      We can separate sounds - or group of sound - by adding a silence (for example: "sound_queue_active(50, SILENT);"). */
#define TONE_CHIME_DURATION     50   // when sounding an hourly chime.
#define TONE_EVENT_DURATION    200   // when scrolling a calendar event.
#define TONE_KEYCLICK_DURATION  50   // when pressing a button ("keyclick").
#define TONE_TIMER_DURATION    100   // when count-down timer reaches 00m00s.

      /* ================================================================== *\
                  ===== END OF CLOCK CONFIGURATION OR OPTIONS =====
      \* ================================================================== */





      /* $TITLE=Definitions and include files. */
      /* $PAGE */
      /* ------------------------------------------------------------------ *\
                          Definitions and include files
                             (in alphabetical order)
      \* ------------------------------------------------------------------ */
      /* Miscellaneous defines. */
#define ALARM_PERIOD              5         // alarm ringer restart every x seconds (part of the whole "nine alarms algorithm").
#define CELSIUS                   0x00
#define CHIME_DAY                 0x02      // hourly chime is ON during defined daily hours (between CHIME_TIME_ON and CHIME_TIME_OFF).
#define CHIME_OFF                 0x00      // hourly chime is OFF.
#define CHIME_ON                  0x01      // hourly chime is ON.
#define COUNT_DOWN_DELAY          7         // number of seconds between each count-down alarm sound burst.
#define CRC16_POLYNOM             0x1021    // different polynom values are used by different authorities. (0x8005, 0x1021, 0x1DCF, 0x755B, 0x5935, 0x3D65, 0x8BB7, 0x0589, 0xC867, 0xA02B, 0x2F15, 0x6815, 0xC599, 0x202D, 0x0805, 0x1CF5)
#define DEFAULT_YEAR_CENTILE      20        // to be used as a default before flash configuration is read (to be displayed in debug log).
#define DELTA_TIME                60000000ll
#define DISPLAY_BUFFER_SIZE       248       // size of framebuffer.
#define EVENT_MINUTE1             14        // (Must be between 0 and 57) Calendar Events will checked when minutes reach this number (should preferably be selected out of peak periods).
#define EVENT_MINUTE2             44        // (Must be between 0 and 57) Calendar Events will checked when minutes reach this number (should preferably be selected out of peak periods).
#define FAHRENHEIT                !CELSIUS  // temperature unit to display.
#define FALSE                     0x00
#define FLAG_OFF                  0x00      // flag is OFF.
#define FLAG_ON                   0x01      // flag is ON.
#define FLAG_POLL                 0x02
#define FLAG_WAIT                 0x03      // special flag asking passive sound queue to wait for active sound queue to complete.
#define FLASH_CONFIG_OFFSET       0x1FF000  // offset in the Pico's 2 MB where to save data. Starting at 2.00MB - 4096 bytes (very end of flash).
#define H12                       FLAG_OFF  // 12-hours time format.
#define H24                       FLAG_ON   // 24-hours time format.
#define MAX_ACTIVE_SOUND_QUEUE    100       // maximum number of "sounds" in the active buzzer sound queue.
#define MAX_ALARMS                9         // total number of alarms available.
#define MAX_LIGHT_SLOTS           24        // number of slots for ambient light level hysteresis.
#define MAX_COMMAND_QUEUE         25        // maximim number of active commands in command queue.
#define MAX_CORE_QUEUE            25        // maximum number of active commands in each circular buffers for inter-core communication (core0-to-core1 and core1-to-core0).
#define MAX_COUNT_DOWN_ALARM_DURATION 30    // maximum period of time (in minutes) during which count-down alarm will ring if not reset by user (quick press on "Set" button).
#define MAX_DHT_READINGS          100       // maximum number of "logic level changes" while reading DHT22 data stream.
#define MAX_EVENTS                50        // maximum number of "calendar events" that can be programmed in the source code.
#define MAX_IR_READINGS           500       // maximum number of "logic level changes" while receiving data from IR remote control.
#define MAX_PASSIVE_SOUND_QUEUE   500       // maximum number of "sounds" in the passive buzzer sound queue.
#define MAX_REMINDERS1            50        // maximum number of "reminders" of type 1 that can be defined.
#define MAX_SCROLL_QUEUE          75        // maximum number of messages in the scroll buffer queue (big enough to cover MAX_EVENTS defined for the same day + a few extra date scrolls).
#define NIGHT_LIGHT_AUTO          0x03      // night light will turn On when ambient light is low enough
#define NIGHT_LIGHT_NIGHT         0x02      // night light On between NightLightTimeOn and NightLightTimeOff.
#define NIGHT_LIGHT_OFF           0x00      // night light always Off.
#define NIGHT_LIGHT_ON            0x01      // night light always On.
#define TIMER_COUNT_DOWN          0x01      // timer mode is "Count Down".
#define TIMER_COUNT_UP            0x02      // timer mode is "Count Up".
#define TIMER_OFF                 0x00      // timer is currently OFF.
#define TRUE                      0x01
#define TYPE_PICO                 0x01      // microcontroller is a Pico
#define TYPE_PICO_W               0x02      // microcontroller is a Pico W


/* DayOfWeek definitions. */
#define ALL 0x00  // All days
#define SUN 0x01  // Sunday
#define MON 0x02  // Monday
#define TUE 0x03  // Tuesday
#define WED 0x04  // Wednesday
#define THU 0x05  // Thursday
#define FRI 0x06  // Friday
#define SAT 0x07  // Saturday


/* Month definitions. */
#define JAN 1   // January
#define FEB 2   // February
#define MAR 3   // March
#define APR 4   // April
#define MAY 5   // May
#define JUN 6   // June
#define JUL 7   // July
#define AUG 8   // August
#define SEP 9   // September
#define OCT 10  // October
#define NOV 11  // November
#define DEC 12  // December


/* Language and locals used. */
#define LANGUAGE_LO_LIMIT 0x00
#define ENGLISH           0x01
#define FRENCH            0x02
#define GERMAN            0x03
#define CZECH             0x04
#define SPANISH           0x05
#define LANGUAGE_HI_LIMIT 0x06


/* List of commands to be processed by command queue handler (while in the "main()" thread context). */
#define COMMAND_PLAY_JINGLE       0x01


/* Inter-core commands / messages. */
/* For target: core 0. */
#define CORE0_DHT_ERROR           0x01
#define CORE0_DHT_READ_COMPLETED  0x02

/* For target: core 1. */
#define CORE1_READ_DHT            0x01


/* "Display modes" used with remote control while in "Generic display mode". */
#define DISPLAY_LO_LIMIT     0x00
#define DISPLAY_TIME         0x01
#define DISPLAY_DATE         0x02
#define DISPLAY_DST          0x03
#define DISPLAY_BEEP         0x04
#define DISPLAY_SCROLLING    0x05
#define DISPLAY_TEMP_UNIT    0x06
#define DISPLAY_LANGUAGE     0x07
#define DISPLAY_TIME_FORMAT  0x08
#define DISPLAY_HOURLY_CHIME 0x09
#define DISPLAY_NIGHT_LIGHT  0x0A
#define DISPLAY_DIM          0x0B
#define DISPLAY_HI_LIMIT     0x0C


/* DST_COUNTRY valid choices (see details in User Guide). */
// #define DST_DEBUG                    /// this define to be used only for intensive DST debugging purposes.
#define DST_LO_LIMIT        0           // this specific define only to make the logic easier in the code.
#define DST_NONE            0           // there is no "Daylight Saving Time" in user's country.
#define DST_AUSTRALIA       1           // daylight saving time for most of Australia.
#define DST_AUSTRALIA_HOWE  2           // daylight saving time for Australia - Lord Howe Island.
#define DST_CHILE           3           // daylight saving time for Chile.
#define DST_CUBA            4           // daylight saving time for Cuba.
#define DST_EUROPE          5           // daylight saving time for European Union.
#define DST_ISRAEL          6           // daylight saving time for Israel.
#define DST_LEBANON         7           // daylight saving time for Lebanon.
#define DST_MOLDOVA         8           // daylight saving time for Moldova.
#define DST_NEW_ZEALAND     9           // daylight saving time for New Zealand.
#define DST_NORTH_AMERICA  10           // daylight saving time for most of Canada and United States.
#define DST_PALESTINE      11           // daylight saving time for Palestine.
#define DST_PARAGUAY       12           // daylight saving time for Paraguay.IR_DISPLAY_GENERIC
#define DST_HI_LIMIT       13           // to make the logic easier in the firmware.


/* List or commands available with remote control. */
#ifdef  IR_SUPPORT
#define IR_LO_LIMIT                  0x00
#define IR_BUTTON_TOP_QUICK          0x01
#define IR_BUTTON_TOP_LONG           0x02
#define IR_BUTTON_MIDDLE_QUICK       0x03
#define IR_BUTTON_MIDDLE_LONG        0x04
#define IR_BUTTON_BOTTOM_QUICK       0x05
#define IR_BUTTON_BOTTOM_LONG        0x06
#define IR_DICE_ROLLING              0x07
#define IR_DISPLAY_AMBIENT_LIGHT     0x08
#define IR_DISPLAY_EVENTS_THIS_WEEK  0x09
#define IR_DISPLAY_EVENTS_TODAY      0x0A
#define IR_DISPLAY_GENERIC           0x0B
#define IR_DISPLAY_OUTSIDE_TEMP      0x0C
#define IR_DISPLAY_SECOND            0x0D
#define IR_FULL_TEST                 0x0E
#define IR_IDLE_TIME                 0x0F
#define IR_POWER_ON_OFF              0x10
#define IR_SILENCE_PERIOD            0x11
#define IR_HI_LIMIT                  0x12
#endif


/* Clock mode definitions. */
#define MODE_LO_LIMIT      0x00
#define MODE_UNDEFINED     0x00  // mode is currently undefined.
#define MODE_ALARM_SETUP   0x01  // user is setting up one or more alarms.
#define MODE_CLOCK_SETUP   0x02  // user is setting up clock parameters.
#define MODE_DISPLAY       0x03  // generic display mode used with IR remote control.
#define MODE_POWER_UP      0x04  // clock has just been powered-up.
#define MODE_SCROLLING     0x05  // clock is scrolling data on the display.
#define MODE_SHOW_TIME     0x06  // clock is displaying time ("normal" mode).
#define MODE_SHOW_VOLTAGE  0x07  // clock is displaying power supply voltage.
#define MODE_TEST          0x08  // clock is in test mode (to disable automatic clock behaviors on the display).
#define MODE_TIMER_SETUP   0x09  // user is setting up a timer.
#define MODE_HI_LIMIT      0x10


/* PWM - "Pulse Wide Modulation" is currently used to control sound on passive buzzer and clock display brightness. */
#define PWM_LO_LIMIT       0x00
#define PWM_SOUND          0x00
#define PWM_BRIGHTNESS     0x01
#define PWM_HI_LIMIT       0x02


/* Alarm setup steps definitions. */
#define SETUP_ALARM_LO_LIMIT  0x00
#define SETUP_ALARM_NUMBER    0x01
#define SETUP_ALARM_ON_OFF    0x02
#define SETUP_ALARM_HOUR      0x03
#define SETUP_ALARM_MINUTE    0x04
#define SETUP_ALARM_DAY       0x05
#define SETUP_ALARM_HI_LIMIT  0x06

/* NOTE: Clock setup step definitions are kept as variables and can be seen in the variables section below. */

/* Setup source definitions. */
#define SETUP_SOURCE_NONE     0x00
#define SETUP_SOURCE_ALARM    0x01
#define SETUP_SOURCE_CLOCK    0x02
#define SETUP_SOURCE_TIMER    0x03


/* Timer setup steps definitions. */
#define SETUP_TIMER_LO_LIMIT  0x00
#define SETUP_TIMER_UP_DOWN   0x01
#define SETUP_TIMER_MINUTE    0x02
#define SETUP_TIMER_SECOND    0x03
#define SETUP_TIMER_READY     0x04
#define SETUP_TIMER_HI_LIMIT  0x05


/* Tags that can be used in process_scroll() function. */
#define TAG_AMBIENT_LIGHT      0xFF   // tag used to scroll current ambient light information.
#define TAG_BME280_DEVICE_ID   0xFE   // tag used to scroll the BME280 device id (should be 0x60 for a "real" BME280).
#define TAG_BME280_TEMP        0xFD   // tag used to display temperature, relative humidity and atmospheric pressure read from an optional BME280 sensor.
#define TAG_WIFI_CREDENTIALS   0xFC
#define TAG_DATE               0xFB   // tag used to scroll current date, temperature and power supply voltage.
#define TAG_DEBUG              0xFA   // tag used to scroll variables for debug purposes, while in main() context.
#define TAG_DHT22_TEMP         0xF9   // tag used to display temperature read from an optional DHT22 temperature and humidity sensor.
#define TAG_DS3231_TEMP        0xF8   // tag used to display ambient temperature read from DS3231 real-time IC in the Green Clock.
#define TAG_DST                0xF7   // tag used to scroll daylight saving time ("DST") information and status on clock display.
#define TAG_FIRMWARE_VERSION   0xF6   // tag used to display Pico Green Clock firmware version.
#define TAG_IDLE_MONITOR       0xF5   // tag used to scroll current System Idle Monitor on clock display.
#define TAG_INFO               0xF4   // tag used to display information while in "main()" context.
#define TAG_NTP_ERRORS         0xF3   // tag used to scroll cumulative number of errors in NTP requests.
#define TAG_NTP_STATUS         0xF2   // tag used to scroll cumulative number of errors in NTP requests.
#define TAG_PICO_TEMP          0xF1   // tag used to display Pico internal temperature.
#define TAG_PICO_TYPE          0xF0   // tag used to display the type of microcontroller installed (Pico or Pico W).
#define TAG_PICO_UNIQUE_ID     0xEF   // tag used to display Pico (flash) unique ID.
#define TAG_QUEUE              0xEE   // tag used to display "Head", "Tail", and "Tag" of currently used scroll queue (for debugging purposes).
#define TAG_TIMEZONE           0xED   // tag used to display Universal Coordinated Time information.
#define TAG_VOLTAGE            0xEC   // tag used to display power supply voltage.


#define SILENT        0
#define WAIT_4_ACTIVE 0xFFFF  // request passive sound queue to wait for active sound queue to complete.


/* Music tones definitions. */
#ifdef PASSIVE_PIEZO_SUPPORT
#define DO_a         262
#define DO_DIESE_a   277
#define RE_a         294
#define RE_DIESE_a   311
#define MI_a         330
#define FA_a         349
#define FA_DIESE_a   370
#define SOL_a        392
#define SOL_DIESE_a  415
#define LA_a         440
#define LA_DIESE_a   466
#define SI_a         494
#define DO_b         523
#define DO_DIESE_b   554
#define RE_b         587
#define RE_DIESE_b   622
#define MI_b         659
#define FA_b         699
#define FA_DIESE_b   740
#define SOL_b        784
#define SOL_DIESE_b  831
#define LA_b         880
#define LA_DIESE_b   932
#define SI_b         988
#define DO_c        1047
#define DO_DIESE_c  1109
#define RE_c        1175
#define RE_DIESE_c  1245
#define MI_c        1319
#define FA_c        1397
#define FA_DIESE_c  1480
#define SOL_c       1568
#define SOL_DIESE_c 1661
#define LA_c        1760
#define LA_DIESE_c  1865
#define SI_c        1976


/* Jingle definitions. */
#define JINGLE_LO_LIMIT  0x00
#define JINGLE_BIRTHDAY  0x01
#define JINGLE_ENCOUNTER 0x02
#define JINGLE_FETE      0x03
#define JINGLE_RACING    0x04
#define JINGLE_HI_LIMIT  0x05
#else
/* Jingle definitions. Placeholder only if not using a passive piezo. */
#define JINGLE_LO_LIMIT  0x00
#define JINGLE_BIRTHDAY  0x00
#define JINGLE_ENCOUNTER 0x00
#define JINGLE_FETE      0x00
#define JINGLE_RACING    0x00
#define JINGLE_HI_LIMIT  0x00
#endif
