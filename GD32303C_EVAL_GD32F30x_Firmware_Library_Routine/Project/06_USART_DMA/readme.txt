/*!
    \file  readme.txt
    \brief description of USART DMA transmitter receiver example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it shows how to use USART0 transmit 
and receive using DMA.
  Firstly, USART0 sends the strings to the hyperterminal and still waits for receiving 
data from the hyperterminal. Then, compare tx_buffer with the rx_buffer, if the tx_buffer 
is the same with the rx_buffer, LED2, LED3, LED4, LED5 light by turns. Otherwise, LED2, LED3, 
LED4, LED5 toggle together.

