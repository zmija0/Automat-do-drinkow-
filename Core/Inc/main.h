/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define StepX_Pin GPIO_PIN_0
#define StepX_GPIO_Port GPIOC
#define Up_Pin GPIO_PIN_5
#define Up_GPIO_Port GPIOA
#define Down_Pin GPIO_PIN_6
#define Down_GPIO_Port GPIOA
#define Ok_Pin GPIO_PIN_7
#define Ok_GPIO_Port GPIOA
#define DirX_Pin GPIO_PIN_0
#define DirX_GPIO_Port GPIOB
#define StepY_Pin GPIO_PIN_2
#define StepY_GPIO_Port GPIOB
#define Enable_Pin GPIO_PIN_14
#define Enable_GPIO_Port GPIOB
#define kX_Pin GPIO_PIN_15
#define kX_GPIO_Port GPIOB
#define DirZ_Pin GPIO_PIN_8
#define DirZ_GPIO_Port GPIOA
#define DirY_Pin GPIO_PIN_9
#define DirY_GPIO_Port GPIOA
#define Woda_Pin GPIO_PIN_7
#define Woda_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define Dioda_Pin GPIO_PIN_8
#define Dioda_GPIO_Port GPIOC
#define STOP_Pin GPIO_PIN_9
#define STOP_GPIO_Port GPIOC
#define STOP_EXTI_IRQn EXTI4_15_IRQn
#define kY_Pin GPIO_PIN_4
#define kY_GPIO_Port GPIOB
#define kZ_Pin GPIO_PIN_5
#define kZ_GPIO_Port GPIOB
#define StepZ_Pin GPIO_PIN_6
#define StepZ_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
