/*!
    \file  readme.txt
    \brief description of the EXMC LCD demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use EXMC 
peripheral to drive LCD. This board uses EXMC_NE0 to support LCD. In this demo, you 
can touch the green button on the LCD screen, then the button will change to red color 
and the corresponding LED will be truned on. If you touch other place of the LCD screen,
the screen will show the error message and all the LEDs will be turned on.
   JP12 must be fitted to the SPI port. 
   P2 and P3 must be fitted to the EXMC port.
   JP24 must be fitted to the Lcd port.
