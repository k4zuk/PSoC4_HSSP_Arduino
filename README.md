# PSoC4 HSSP on Arduino
This is a port of AN84858 to Arduino.  
[AN84858 - PSoC®4 Programming Using an External Microcontroller (HSSP)](https://www.cypress.com/documentation/application-notes/an84858-psoc-4-programming-using-external-microcontroller-hssp)


## Requirement
The HSSP firmware contains a flash ROM image of the target PSoC4 device; therefore, the size of flash ROM on the Arduino board must be larger than the target has. (e.g. ESP32 DEVKITV1)


## Pin Assignments
The definitions of pin assignments are in SWD_PhysicalLayer.h file.
```
SWD_PhysicalLayer.h
  #define SWDIO_PIN   4
  #define SWDCK_PIN   2
  #define XRES_PIN    15
```


## Hardware Connections for HSSP Programming
|Arduino-ESP32 | --- |PSoC4 |
|-------------:|:---:|:-----|
|3V3           | --- |VDDD  |
|GND           | --- |VSSD  |
|XRES_PIN (15) | --- |XRES  |
|SWDCK_PIN (2) | --- |SWDCK |
|SWDIO_PIN (4) | --- |SWDIO |


## HSSP Programming
 1. Prepare a hex format file for the target PSoC4 device.
 2. Conver to HexImage.h and HexImage.c files using "HexFile Parser.exe" in AN84858, and then put these files into the same folder as PSoC4_HSSP_Arduino.ino file.
 3. Upload firmware to the Arduino board.

After upload completed or to reset the Arduino board then start programming. The progress is displayed on the terminal.


## My Testing Environment
|Item           |Equipment      |
|---------------|---------------|
|Arduino board  |ESP32 DEVKITV1 |
|PSoC4 device   |CY8CKIT-142 (PSoC4 BLE Module) |
|PSoC4 firmware |[AN68272 - PSoC® 3, PSoC 4, PSoC 5LP, and PSoC Analog Coprocessor UART Bootloader](https://www.cypress.com/documentation/application-notes/an68272-psoc-3-psoc-4-psoc-5lp-and-psoc-analog-coprocessor-uart) |
