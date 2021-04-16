/*!
    \file  readme.txt
    \brief description of calendar demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

  This demo is based on the GD32303C-EVAL-V1.0 board, it explains how to configure the RTC module. 
In this demo, RTC peripheral is configured to generate alarm and display calendar.
  Select LXTAL as RTC clock source. And the HyperTerminal should be connected to the 
evaluation board via COM1.
  After start-up,whether the BKP data register is written to a key value or not.
If the value is incorrect, the program will ask to set the time on the HyperTerminal.
At the same time,set current time add 10 second as alarm time.After 10 second,the
alarm note will displayed on the HyperTerminal and turn on LEDs.If the  key value is 
correct, the calendar will be displayed on the HyperTerminal. 
  The RTC module is in the Backup Domain, and is not reset by the system reset.