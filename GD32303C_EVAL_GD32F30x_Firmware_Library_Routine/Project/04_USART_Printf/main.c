/*!
    \file  main.c
    \brief USART printf demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"
#include "systick.h"
#include <stdio.h>

void led_init(void);
void led_flash(int times);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* initialize the LEDs */
    led_init();
    
    /* configure systick */
    systick_config();
    
    /* flash the LEDs for 1 time */
    led_flash(1);
    
    /* configure EVAL_COM1 */
    gd_eval_com_init(EVAL_COM1);
    
    /* configure TAMPER key */
    gd_eval_key_init(KEY_TAMPER, KEY_MODE_GPIO);
    
    /* output a message on hyperterminal using printf function */
    printf("\r\n USART printf example: please press the Tamper key \r\n");
    
    /* wait for completion of USART transmission */
    while(RESET == usart_flag_get(EVAL_COM1, USART_FLAG_TC)){
    }
    while(1){
        /* check if the tamper key is pressed */
        if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
            delay_1ms(50);
            if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
                delay_1ms(50);
                if(RESET == gd_eval_key_state_get(KEY_TAMPER)){
                    /* turn on LED2 */
                    gd_eval_led_on(LED2);
                    /* output a message on hyperterminal using printf function */
                    printf("\r\n USART printf example \r\n");
                    /* wait for completion of USART transmission */
                    while(RESET == usart_flag_get(EVAL_COM1, USART_FLAG_TC)){
                    }
                }else{
                    /* turn off LED2 */
                    gd_eval_led_off(LED2);
                }
            }else{
                /* turn off LED2 */
                gd_eval_led_off(LED2);
            }
        }else{
            /* turn off LED2 */
            gd_eval_led_off(LED2);
        }
    }
}

/*!
    \brief      initialize the LEDs
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init(void)
{
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
    gd_eval_led_init(LED5);
}

/*!
    \brief      flash the LEDs for test
    \param[in]  times: times to flash the LEDs
    \param[out] none
    \retval     none
*/
void led_flash(int times)
{
    int i;
    for(i=0; i<times; i++){
        /* delay 400 ms */
        delay_1ms(400);

        /* turn on LEDs */
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED3);
        gd_eval_led_on(LED4);
        gd_eval_led_on(LED5);

        /* delay 400 ms */
        delay_1ms(400);
        /* turn off LEDs */
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED3);
        gd_eval_led_off(LED4);
        gd_eval_led_off(LED5);
    }
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(EVAL_COM1, (uint8_t)ch);
    while(RESET == usart_flag_get(EVAL_COM1, USART_FLAG_TBE));
    return ch;
}
