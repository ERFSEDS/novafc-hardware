/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define FIRE4_Pin GPIO_PIN_13
#define FIRE4_GPIO_Port GPIOC
#define FL_CS_Pin GPIO_PIN_0
#define FL_CS_GPIO_Port GPIOA
#define SD_CS_Pin GPIO_PIN_1
#define SD_CS_GPIO_Port GPIOA
#define FIRE1_Pin GPIO_PIN_2
#define FIRE1_GPIO_Port GPIOA
#define FIRE2_Pin GPIO_PIN_3
#define FIRE2_GPIO_Port GPIOA
#define ARM1_Pin GPIO_PIN_4
#define ARM1_GPIO_Port GPIOA
#define GPIO5_Pin GPIO_PIN_5
#define GPIO5_GPIO_Port GPIOA
#define GPIO4_Pin GPIO_PIN_6
#define GPIO4_GPIO_Port GPIOA
#define GPIO3_Pin GPIO_PIN_7
#define GPIO3_GPIO_Port GPIOA
#define GPIO2_Pin GPIO_PIN_0
#define GPIO2_GPIO_Port GPIOB
#define INT1_Pin GPIO_PIN_1
#define INT1_GPIO_Port GPIOB
#define INT2_Pin GPIO_PIN_2
#define INT2_GPIO_Port GPIOB
#define ACCELEROMETER_CS_Pin GPIO_PIN_10
#define ACCELEROMETER_CS_GPIO_Port GPIOB
#define BAROMETER_CS_Pin GPIO_PIN_12
#define BAROMETER_CS_GPIO_Port GPIOB
#define IMU_CS_Pin GPIO_PIN_8
#define IMU_CS_GPIO_Port GPIOA
#define IMU_INT_Pin GPIO_PIN_9
#define IMU_INT_GPIO_Port GPIOA
#define FSYNC_Pin GPIO_PIN_10
#define FSYNC_GPIO_Port GPIOA
#define FIRE3_Pin GPIO_PIN_4
#define FIRE3_GPIO_Port GPIOB
#define ARM2_Pin GPIO_PIN_5
#define ARM2_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_6
#define BUZZER_GPIO_Port GPIOB
#define LED_BLUE_Pin GPIO_PIN_7
#define LED_BLUE_GPIO_Port GPIOB
#define LED_GREEN_Pin GPIO_PIN_8
#define LED_GREEN_GPIO_Port GPIOB
#define LED_RED_Pin GPIO_PIN_9
#define LED_RED_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
