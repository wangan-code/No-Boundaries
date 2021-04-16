/*!
    \file  main.c
    \brief GPIO keyboard polling demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"
#include "systick.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{  
    gd_eval_key_init(KEY_TAMPER,KEY_MODE_GPIO);
    systick_config();
    gd_eval_led_init(LED2);

    while(1){
        if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
            /* delay 50ms for software removing jitter */
            delay_1ms(50);
            if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
                gpio_bit_write(LED2_GPIO_PORT, LED2_PIN, (bit_status)((1 - gpio_output_bit_get(LED2_GPIO_PORT, LED2_PIN))));
                while(RESET == gd_eval_key_state_get(KEY_TAMPER));
            }
        }
    }
}
