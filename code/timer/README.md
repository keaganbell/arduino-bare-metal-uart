# Overview
This example expands on the blink example to make the LED turn on and off with a non-blocking timer. It puts Timer/Counter Control Register 0 in *Clear Timer on Compare* (CTC) mode. When the clock value "overflows", an interrupt is triggered prompting our program to increment the milliseconds counter.

This timer is used similarly to the Arduino API function millis(). Now the program can just check the counter and power the LED as necessary instead of blocking the program to waste CPU cycles to wait for the next time to toggle the LED.

You should be able to plug the Arduino into your PC and run the build script. Be sure to edit the parameters for your setup.
```CMD
build.bat -tar timer -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```
Note that the output port is now PORTB3. So you need an LED attached to gpio pin 11 to see the results.
