/*!
    \file  readme.txt
    \brief description of USART printf example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use the key control
the LED and how to retarget the C library printf function to the USART. If the tamper
key is detected pressed, LED2 will be turned on, and the EVAL_COM1 will print "USART 
printf example", otherwise LED2 will be turned off.