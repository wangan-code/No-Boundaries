/*!
    \file  main.c
    \brief I2S audio player demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include <stdio.h>
#include "gd32f30x.h"
#include "systick.h"
#include "gd32f303c_eval.h"
#include "pcm1770.h"

void test_status_led_init(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* systick configuration*/
    systick_config();

    /* configure the led GPIO */
    test_status_led_init();

    nvic_priority_group_set(NVIC_PRIGROUP_PRE0_SUB4);
    nvic_irq_enable(SPI1_IRQn, 0, 1);

    /* I2S code test */
    {  
        /* initialize SPI, I2S and audio file */
        pcm1770_init(AUDIO_FILE_ADDRESS );
        /* audio play start */
        pcm1770_audio_play();
    }

    while(1);
}

/*!
    \brief      test status led initialize
    \param[in]  none
    \param[out] none
    \retval     none
*/
void test_status_led_init(void)
{
    /* initialize the leds */
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
    gd_eval_led_init(LED5);

    /* turn on all of leds */
    gd_eval_led_on(LED2);
    gd_eval_led_on(LED3);
    gd_eval_led_on(LED4);
    gd_eval_led_on(LED5);
    
    delay_1ms(500);
    
    /* close all of leds */
    gd_eval_led_off(LED2);
    gd_eval_led_off(LED3);
    gd_eval_led_off(LED4);
    gd_eval_led_off(LED5);
}
