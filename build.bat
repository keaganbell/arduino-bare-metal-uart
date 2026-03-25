@echo off

setlocal enabledelayedexpansion

:: parse parameters

:parse
if "%~1"=="" goto done

if /i "%~1"=="-port" (
    set port=%~2
    shift
    shift
    goto parse
)

if /i "%~1"=="-avr" (
    set avr=%~2
    shift
    shift
    goto parse
)

shift
goto parse
:done

if "%avr%"=="" (
	echo please specify path to avr toolchain.
	echo example: build.bat -avr C:\avr\avr8-gnu-toolchain-win32_x86_64\
	exit /b 1
)
if "%avr:~-1%"=="\" set "avr=%avr:~0,-1%"
echo avr toolchain: %avr%

if "%port%"=="" (
	echo please specify name of serial port.
	echo example: build.bat -port COM5
	exit /b 1
)

:: find toolchain
set "cc=%avr%\bin\avr-gcc.exe"
if not exist %cc% echo failed to find avr-gcc.exe. check the avr toolchain path. && exit /b 1
set "cpy=%avr%\bin\avr-objcopy.exe"
if not exist %cpy% echo failed to find avr-objcopy.exe. check the avr toolchain path. && exit /b 1
set "dude=%avr%\bin\avrdude.exe"
if not exist %dude% echo failed to find avrdude.exe. check the avr toolchain path. && exit /b 1


:: set up folders
if not exist build mkdir build
pushd build


:: compile the code
%cc% -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o ..\code\firmware.c || exit /b 1
%cc% -o led.bin led.o


:: convert to correct format
%cpy% -O ihex -R .eeprom led.bin led.hex || exit /b 1


:: flash the program
%dude% -F -V -c arduino -p ATMEGA328P -P %port% -b 115200 -U flash:w:led.hex

