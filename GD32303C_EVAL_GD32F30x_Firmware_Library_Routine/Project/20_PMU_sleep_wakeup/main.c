/*!
    \file  main.c
    \brief sleep wakeup through USART interrupt
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"

void led_config(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    uint32_t i;
    /* configure EVAL_COM1 */
    gd_eval_com_init(EVAL_COM1);
    /* USART interrupt configuration */
    nvic_irq_enable(USART0_IRQn, 0, 0);
    /* enable EVAL_COM1 receive interrupt */
    usart_interrupt_enable(EVAL_COM1, USART_INT_RBNE);
    /* configure led */
    led_config();
    /* enable PMU clock */ 
    rcu_periph_clock_enable(RCU_PMU);
    /* enter sleep mode */
    pmu_to_sleepmode(WFI_CMD);
    
    while(1){
        /* set all the leds on */
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED3);
        gd_eval_led_on(LED4);
        gd_eval_led_on(LED5);
        for(i=0; i<0xffffff; i++){
        }
        /* set all the leds off */
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED3);
        gd_eval_led_off(LED4);
        gd_eval_led_off(LED5);
        i = 0;
        for(i=0; i<0xffffff; i++){
        }
    }
}

/*!
    \brief      configure led
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_config(void)
{
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
    gd_eval_led_init(LED5);
}
