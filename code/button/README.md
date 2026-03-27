# Overview
This example expands on the PWM example. A button is connected to pin 7 on port D which corresponds to Arduino gpio pin 7.
Pin 7 is initialized to input mode and set to "pull up" so that it is considered *active* when the button is pressed and the pin is pulled low (to ground).
The button is updated every 5 ms to avoid "bouncing." The delay can be adjusted in code by defining the BUTTON_LATENCY_MS definition.

To run the program, be sure to edit the parameters for your setup.
```CMD
build.bat -tar button -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```
Note that the output port is PORTB1. So you need an LED attached to gpio pin 9 to see the results.
Input is observed on PIND7. So the button should be connected to gpio pin 7. The output of the button goes to ground.

![Button Example Schematic](button_led_pwm_schematic.png)