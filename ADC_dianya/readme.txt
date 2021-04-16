/*!
    \file  readme.txt
    \brief description of ADC_Temperature_Vrefint example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use 
the ADC to convert analog signal to digital data.The ADC is configured 
in dependent mode, inner channel 16(temperature sensor channel) and channel 17
(VREFINT channel) are chosen as analog input pin.
  As the AD convertion begins by software,the converted data is stored in the 
ADC_IDATAx register,where the x is 0 to 1.USART will print these values.

Notice: Because there is an offset,when inner temperature sensor is used to detect 
accurate temperature,an external temperature sensor part should be used to calibrate 
the offset error.

