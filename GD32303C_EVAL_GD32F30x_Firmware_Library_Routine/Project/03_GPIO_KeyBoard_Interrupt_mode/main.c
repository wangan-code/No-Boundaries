/*!
    \file  main.c
    \brief GPIO keyboard interrupt demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{  
    gd_eval_key_init(KEY_TAMPER, KEY_MODE_EXTI);
    gd_eval_led_init(LED2);
    
    while(1){
    }
}
