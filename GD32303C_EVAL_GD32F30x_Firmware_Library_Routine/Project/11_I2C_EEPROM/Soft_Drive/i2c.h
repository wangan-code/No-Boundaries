/*!
    \file  i2c.h
    \brief the header file of I2C
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#ifndef I2C_H
#define I2C_H

#include "gd32f30x.h"

#define I2C0_SPEED              400000
#define I2C0_SLAVE_ADDRESS7     0xA0
#define I2C_PAGE_SIZE           8

/* configure the GPIO ports */
void gpio_config(void);
/* configure the I2C0 interfaces */
void i2c_config(void);

#endif  /* I2C_H */
