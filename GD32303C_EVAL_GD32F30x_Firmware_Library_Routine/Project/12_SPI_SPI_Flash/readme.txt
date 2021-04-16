/*!
    \file  readme.txt
    \brief description of the SPI_SPI_Flash demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to read data from 
flash and write data to flash using SPI0. The access result will be printed by COM1.

  After system start-up, printf some related information and read the id of the flash.
If the id is not equal to SFLASH_ID, print the fail information. If not, write and 
read data from the SPI flash. Then check whether the rx_buffer and tx_buffer are the 
same and print the result after that.
  
  At last, turn on and off the LED one by one.

  When use GD32303C-EVAL-V1.0 board, you should jump the JP12 to SPI.
