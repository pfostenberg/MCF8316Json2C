
Goal
====

TI has some new devices for BLDC control

- MCF8316A for sine odial motors
- MCT8316A for trapezoid types

Both have the same IC and PIN out.

With some nice TI utilities you can create con fig files like MCF8316A_example.json.

- https://dev.ti.com/gallery/view/BLDC/MCF8316A_GUI
- https://dev.ti.com/gallery/view/BLDC/MCT8316A_GUI

With this project I wanted to create C file to include in Microchip or other embedded tools.


Start the exe.... MCF/MCF in the RET directory open the save file.
Run it the it make a MCF8316A_example.c
You need to define what Type of CPU you want.

Update 01/2024
==============

The MCF8316A has a silicon bug see erata

https://e2e.ti.com/support/motor-drivers-group/motor-drivers/f/motor-drivers-forum/1085557/mcf8316a-driver-stops-working-while-reading-register-with-i2c

The only way reported is not to use I2C at all when the motor is spinning.
No stable change of RPM via I2C.

Acording to the support there will be a fix with MCF8316C Q1.

Next I test if this also works with this tool.








