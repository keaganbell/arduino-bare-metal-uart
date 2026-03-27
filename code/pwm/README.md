# Overview
This example uses two timers to pulse an LED smoothly between lit and unlit. The Timer/Counter Control Register 0 is set to CTC mode and the Timer/Counter Control Register 1 is set to fast PWM 8-bit mode.

The register that I chose to use for PWM is OC1A which is associated with PORTB1 on the ATmega328P which is gpio pin ~9 on the Arduino UNO.

You should be able to plug the Arduino into your PC and run the build script. Be sure to edit the parameters for your setup.
```CMD
build.bat -tar pwm -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```
Note that the output port is now PORTB1. So you need an LED attached to gpio pin 9 to see the results.
You can also edit the code and change LED_PULSE_TIME_MS to change the speed at which the LED pulses.

![Shift Example Schematic](avr_shift_schematic.png)
