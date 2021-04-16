/*!
    \file  readme.txt
    \brief description of ADC0_ADC1_Regular_Parallel_mode example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use ADC0 and ADC1 regular_parallel 
mode convert function. PC3 and PC5 are configured as AIN mode. PC5 pin connect to the external voltage 
input. PC3 is the output voltage of the slide rheostat VR1 on board.
  TIMER0_CH0 is the trigger source of ADC0. When the rising edge of TIMER0_CH0 coming, ADC0 and ADC1 
regular channel are triggered at the same time. The values of ADC0 and ADC1 are transmitted to array 
adc_value[] by DMA.
  We can watch array adc_value[] by USART.

  Keep PC5 pin should not be reused by other peripherals.