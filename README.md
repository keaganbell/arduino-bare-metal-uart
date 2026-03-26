# Overview
This repo contains example code for learning the the avr family microcontroller feature set. This project primarily uses the ATmega328P (Arduino UNO) without the IDE or Ardiuno system libraries to focus on the foundations of bare-metal programming in C. It uses the [AVRtoolchain](https://tinusaur.com/guides/avr-gcc-toolchain/) to compile C code to .hex files and flashes it to the Arduino with avrdude. See the build instructions for how to choose which code example to compile and run on the board.

## Requirements
- Windows (for now).
- Need avr-gcc, avr-objcopy, and avrdude programs from the [AVR toolchain](https://tinusaur.com/guides/avr-gcc-toolchain/).

## Build Instructions
After isntalling the avr toolchain, just run build.bat with the specified parameters. It should produce a build folder and a target folder depending on which example was specified with the -tar flag. It will also flash the program to the board. Make sure the Arduino is plugged in to your PC via USB. Edit path below to your installation of the avr toolchain. The specified path should contain the .\bin\ folder with the toolchain executables.
Example:
``` CMD
build.bat -tar blink -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```

To clean build artifacts, just delete the folder and re-run the build script with desired arguments. The script will take care of making and moving the necessary files.

### Build Flags
The build process is setup to build just a single translation unit. The main.c file should just include all the code files .h and .c alike.
- -tar *target*: specify which example to build and flash. The script will search for a folder in .\code\ named *target* and try to compile a file named *target_main.c*
- -port *port_name*: specify which port the Arduino is plugged into. On windows, you can check the Device Manager for Ports with connected devices or use the cmd *mode* in a cmd prompt.
- -avr \filepath\: specify the path to the avr toolchain. The specified path should contain a \bin\ folder with the avr-gcc.exe, avr-objcopy.exe, and avrdude.exe executables.
 