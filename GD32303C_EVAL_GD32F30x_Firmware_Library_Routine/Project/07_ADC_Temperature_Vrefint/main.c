/*!
    \file  main.c
    \brief ADC Temperature Vrefint demo
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-23, V1.0.0, demo for GD32F30x
*/

#include "gd32f30x.h"
#include "gd32f303c_eval.h"
#include "systick.h"
#include <stdio.h>
#define BOARD_ADC_CHANEL    ADC_CHANNEL_13
#define ADC_GPIO_PORT       GPIOC
#define ADC_GPIO_PIN        GPIO_PIN_3

uint16_t  adc_value;
//float temperature;
float vref_value;

void rcu_config(void);
void gpio_config(void);
void dma_config(void);
void adc_config(void);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* system clocks configuration */
    rcu_config();
    /* configure systick */
    systick_config();  
	/*GPIO configuration*/
	  gpio_config();
	/*DMA configuration*/
    dma_config();
    /* ADC configuration */
    adc_config();
    /* USART configuration */
    gd_eval_com_init(EVAL_COM1);
			/* ADC software trigger enable */
	  adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);     //规则通道
    while(1){

    /* delay a time in milliseconds */
    delay_1ms(2000);
      
     /* value convert  */
     //  temperature = (1.43 - ADC_IDATA0(ADC0)*3.3/4096) * 1000 / 4.3 + 25;
    vref_value = adc_regular_data_read(ADC0) * 3.3 / 4096;
      
     /* value print */
     //  printf(" the temperature data is %2.0f degrees Celsius\r\n", temperature);
    printf(" the reference voltage data is %5.3fV \r\n", vref_value);
    printf(" \r\n");
    }
}

/*!
    \brief      configure the different system clocks
    \param[in]  none
    \param[out] none
    \retval     none
*/
void rcu_config(void)
{
	  /* enable GPIOA clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    /* enable ADC clock */
    rcu_periph_clock_enable(RCU_ADC0);
    /* config ADC clock */
    rcu_adc_clock_config(RCU_CKADC_CKAPB2_DIV6);
	  /* enable DMA0 clock */
    rcu_periph_clock_enable(RCU_DMA0);
	  
}

/*!
    \brief      configure the ADC peripheral
    \param[in]  none
    \param[out] none
    \retval     none
*/

void gpio_config(void)
{
    /* config the GPIO as analog mode */
    gpio_init(ADC_GPIO_PORT, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, ADC_GPIO_PIN);
}

void dma_config(void)
{
    /* ADC_DMA_channel configuration */
    dma_parameter_struct dma_data_parameter;
    
    /* ADC DMA_channel configuration */
    dma_deinit(DMA0, DMA_CH0);
    
    /* initialize DMA single data mode */
    dma_data_parameter.periph_addr  = (uint32_t)(&ADC_RDATA(ADC0));
    dma_data_parameter.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_data_parameter.memory_addr  = (uint32_t)(&adc_value);
    dma_data_parameter.memory_inc   = DMA_MEMORY_INCREASE_DISABLE;
    dma_data_parameter.periph_width = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_data_parameter.memory_width = DMA_MEMORY_WIDTH_16BIT;  
    dma_data_parameter.direction    = DMA_PERIPHERAL_TO_MEMORY;
    dma_data_parameter.number       = 1;
    dma_data_parameter.priority     = DMA_PRIORITY_HIGH;
    dma_init(DMA0, DMA_CH0, &dma_data_parameter);
    dma_circulation_enable(DMA0, DMA_CH0);
  
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH0);
}
void adc_config(void)
{
    /* reset ADC */
    adc_deinit(ADC0);      //复用ADC外设
    /* ADC mode config */
    adc_mode_config(ADC_MODE_FREE);    //配置ADC同步模式
    /* ADC contineous function enable */
    adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, ENABLE);   // ADC连续模式使能
    /* ADC scan mode disable */
    adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE);  
    /* ADC data alignment config */
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);   //ADC数据右对齐配置
    /* ADC channel length config */
    adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL, 1);    //ADC通道长度配置
 
    /* ADC regular channel config */
    adc_regular_channel_config(ADC0, 0,  ADC_CHANNEL_13 , ADC_SAMPLETIME_55POINT5);//采样时间；55.5个ADC工作周期
    /* ADC trigger config */
    adc_external_trigger_source_config(ADC0, ADC_REGULAR_CHANNEL, ADC0_1_2_EXTTRIG_REGULAR_NONE);//触发条件 none是不使用外部触发，只使用软件触发
    adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, ENABLE);   //配置adc外部触发
    
    /* enable ADC interface */
    adc_enable(ADC0);
    delay_1ms(1);
    /* ADC calibration and reset calibration */
    adc_calibration_enable(ADC0);

    /* ADC DMA function enable */
    adc_dma_mode_enable(ADC0);
    /* ADC software trigger enable */
    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);
}

/* retarget the C library printf function to the USART */



int fputc(int ch, FILE *f)
{
    usart_data_transmit(EVAL_COM1, (uint8_t) ch);
    while (RESET == usart_flag_get(EVAL_COM1,USART_FLAG_TBE));
    return ch;
}


