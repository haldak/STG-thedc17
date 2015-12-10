/**
  ******************************************************************************
  * @file    PaperCut
  * @author  Zion
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
//#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_it.h"
#include "stm32f4xx.h"
#include "usart.h"
#include "timer.h"
#include "pwm.h"
#include "adc_dma.h"
#include "infrared.h"
#include "common.h"
#include "imu.h"
#include "motor.h"
#include <math.h>
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup TIM_PWM_Output
  * @{
  */ 

uint16_t PrescalerValue = 0;
char comptitionStart = 0;
  __IO uint16_t ADC3ConvertedValue[8] ;
  __IO uint16_t ADC1ConvertedValue[10];
//extern __IO uint32_t ADC3ConvertedVoltage ;
extern struct RECEIVE ReceiveAI ;
extern struct imu_data IMU_Data;
/**
  * @brief  Main programm
  * @param  None
  * @retval None
  */
int main(void)
{
  TIM1_TIM3_Config();
	pwm1_config(PrescalerValue);
  USART2_Configuration();
  UART5_Configuration();
  ADC1_CH4_CH5_DMA_Config();
	//ADC3_8CH_DMA_Config();
	
  Infrared_GPIO_Config();
	
  TIM2_Config();
	TIM5_Config();
	motor_config();
	motor_sleep();
  while (1)
  {
		//printf("%d\n",ADC1ConvertedValue[0]);
		//printf("%d\n",ADC1ConvertedValue[4]);
//		float y = culculateAngle();
		//printf("hello");
	}
}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  while (1)
  {}
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
