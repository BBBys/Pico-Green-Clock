#include "typedefs.h"
void adjust_clock_brightness(void);
/* Read ambient light level from Pico's analog-to-digital gpio. */
UINT16 adc_read_light(void);
/* Send a string to an external terminal emulator program through Pico's UART (or serial port). */
void uart_send(UINT LineNumber, UCHAR* Format, ...);

/* Set the duty cycle for the PWM used for clock display brightness. */
void pwm_set_duty_cycle(UINT8 DutyCycle);

