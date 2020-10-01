/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FLASH_SD_Pin GPIO_PIN_4
#define FLASH_SD_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_5
#define SD_CS_GPIO_Port GPIOC
#define BARO_CS_Pin GPIO_PIN_0
#define BARO_CS_GPIO_Port GPIOB
#define ACCEL_CS_Pin GPIO_PIN_1
#define ACCEL_CS_GPIO_Port GPIOB
#define IMU_GYRO_CS_Pin GPIO_PIN_2
#define IMU_GYRO_CS_GPIO_Port GPIOB
#define IMU_ACCEL_CS_Pin GPIO_PIN_10
#define IMU_ACCEL_CS_GPIO_Port GPIOB
#define Buzzer_Pin GPIO_PIN_13
#define Buzzer_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_15
#define LED_B_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_6
#define LED_R_GPIO_Port GPIOC
#define Arm_Pin GPIO_PIN_8
#define Arm_GPIO_Port GPIOC
#define Fire1_Pin GPIO_PIN_9
#define Fire1_GPIO_Port GPIOC
#define Fire2_Pin GPIO_PIN_8
#define Fire2_GPIO_Port GPIOA
#define Continuity1_Pin GPIO_PIN_9
#define Continuity1_GPIO_Port GPIOA
#define Continuity2_Pin GPIO_PIN_10
#define Continuity2_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
