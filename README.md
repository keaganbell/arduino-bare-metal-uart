# Overview
This project explores the foundations of interface communication for the Atmega328P (Arduino UNO) without the IDE or helper libraries. It uses the [AVR toolchain](https://tinusaur.com/guides/avr-gcc-toolchain/) to compile C code to .hex files and flashes it to the Arduino with avrdude. Running the Arduino program should light up an LED at 50% brightness. Running the PC program allows the user to type in a number between 0 and 100 to change the brightness of the LED over serial communication.

## Requirements
- Windows (for now). Writing to files and file descriptors is OS-specific. Porting to other platforms is trivial.
- [AVR toolchain](https://tinusaur.com/guides/avr-gcc-toolchain/). Need avr-gcc, avr-objcopy, and avrdude programs.

## Build Instructions
After isntalling the avr toolchain, just run build.bat. It should produce a build folder with the PC program executable and the Arduino code. It will also flash the program to the board. Make sure the Arduino is plugged in to your PC via USB.
``` CMD
build.bat -port COM5 -avr C:\Keagan\Programs\avr8-gnu-toolchain-win32_x86_64\
```