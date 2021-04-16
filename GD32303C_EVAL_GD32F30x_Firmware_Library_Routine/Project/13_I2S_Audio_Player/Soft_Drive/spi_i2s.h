/*!
    \file  spi_i2s.h
    \brief the header file of spi_i2s.c.
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#ifndef __SPI_I2S_H
#define __SPI_I2S_H

#include "gd32f30x.h"

/* configure the I2S1 and SPI0 GPIO */
void spi_i2s_gpio_config(void);
/* configure the I2S1 and SPI0 */
void spi_i2s_config(uint16_t standard, uint16_t mclk_output, uint16_t audio_freq);

#endif /*__SPI_I2S_H*/
