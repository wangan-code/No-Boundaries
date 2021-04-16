/*!
    \file  at24cxx.h
    \brief the header file of AT24Cxx
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#ifndef AT24CXX_H
#define AT24CXX_H

#include "gd32f30x.h"

#define EEP_FIRST_PAGE         0x00

#define I2C_OK                 0
#define I2C_FAIL               1

/* I2C read and write functions */
uint8_t i2c_24c02_test(void);
/* initialize EEPROM address */
void i2c_eeprom_init(void);
/* write one byte to the EEPROM */
void eeprom_byte_write(uint8_t* p_buffer, uint8_t write_address);
/* write more than one byte to the EEPROM */
void eeprom_page_write(uint8_t* p_buffer, uint8_t write_address, uint8_t number_of_byte);
/* write buffer of data to the EEPROM */
void eeprom_buffer_write(uint8_t* p_buffer, uint8_t write_address, uint16_t number_of_byte);
/* read data from the EEPROM */
void eeprom_buffer_read(uint8_t* p_buffer, uint8_t read_address, uint16_t number_of_byte);
/* wait for EEPROM standby state */
void eeprom_wait_standby_state(void);

#endif  /* AT24CXX_H */
