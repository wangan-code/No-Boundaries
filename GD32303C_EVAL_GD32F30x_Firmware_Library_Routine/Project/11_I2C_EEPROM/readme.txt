/*!
    \file  readme.txt
    \brief description of using the I2C bus to write and read EEPROM
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it provides a description 
of how to use the I2C bus to write and read EEPROM. The access result will be 
printed by COM1.

  Procedures sequentially writes 256 bytes of data to the EEPROM from the 0x00 
address, and then the program sequentially reads 256 bytes of data from the 
EEPROM from the 0x00 address. Compare the written data and read data, if the 
same,"I2C-AT24C02 test passed!" will be printed, while the board of the four
LED lights start flashing, otherwise "Err:data read and write aren't matching."
will be printed, while the four LEDs light will on.

