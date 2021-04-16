/*!
    \file  readme.txt
    \brief description of the sleep wakeup through USRAT interrupt demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This example is based on the GD32303C-EVAL-V1.0 board, it shows how pmu enter sleep mode 
and how to wakeup it. After power-on, all the LEDs are off. The mcu will enter sleep 
mode and the software stop running. When the USART0 receives a byte of data from the 
hyperterminal, the mcu will be wakeup from a receive interrupt. And all the leds will 
spark.