/*!
    \file  readme.txt
    \brief description of RCU_Clock_Out example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-05-19, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use the clock out function of RCU. 
When program is running, user could press the tamper key to select different clock source to output.
Demo has three clock source, once the key is pressed, the source will change and the corresponding 
led will light on. Debug information can be printed from COM1 by using USART0. The clock output pin 
is PA8. 