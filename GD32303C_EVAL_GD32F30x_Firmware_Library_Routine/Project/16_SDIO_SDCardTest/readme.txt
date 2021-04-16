/*!
    \file  readme.txt
    \brief description of SD card read and write example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This example is based on the GD32303C-EVAL-V1.0 board, it shows how to use SDIO to read 
or write to SD card. Firstly, all the LEDs flash once for test. After initializing the card 
successfully, print out the detailed information of the card by USART. Then write a block 
of data to the card and read. If any error occurs, print the error message and turn on LED2, 
LED4 and turn off LED3, LED5. After that, do the lock and unlock operation test. Lock the 
card first and try to erase the data of the card. Then unlock the card and erase the card. 
If any error occurs, print the error message and turn on LED2, LED4 and turn off LED3, LED5. 
Last is the multiple blocks operation test. If no error occurs, turn on all the LEDs.

  Uncomment the macro DATA_PRINT to print out the data and display them through HyperTerminal.

