/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd_i2c.h"
#include <stdbool.h>
#include <stdio.h>
#include "engines_ad.h"
#include "selection_ad.h"
#include "back_ad.h"
#include "drinks_ad.h"
//#include "buttons_ad.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
struct lcd_disp display;
int time = 20;
int number = 0;
int but_delay = 500;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
  back_to_start(); //powrót do współrzędnych 0,0,0 (potrzebne w razie np wyłączenia zasilania w trakcie pracy)
  display.addr = (0x27 << 1);
  display.bl = true;
  lcd_init(&display);
  sprintf((char *)display.f_line, "Cleaning");
  lcd_display(&display);

  //sprintf((char *)display.f_line, "jeden");
  //lcd_display(&display);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  void show()		//funkcja odpowiedzialna za wyświetlanie nazw drinków na wyświetlaczu
  {
	  if(number == 0)	//sprawdzenie w jakim miejscu się znajdujemy
	  {
		  sprintf((char *)display.f_line, "Cleaning");	//podanie tekstu na odpowiednią linię (f_line - górna)
		  lcd_display(&display);	//wyświetlenie obrazu
	  }
	  if(number == 1)
	  {
		  sprintf((char *)display.f_line, "Californication");
		  lcd_display(&display);
	  }
	  if(number == 2)
	  {
		  sprintf((char *)display.f_line, "Sex on the beach");
		  lcd_display(&display);
	  }
	  if(number == 3)
	  {
		  sprintf((char *)display.f_line, "Cuba Libre");
		  lcd_display(&display);
	  }
	  if(number == 4)
	  {
		  sprintf((char *)display.f_line, "Mohito");
		  lcd_display(&display);
	  }
	  if(number == 5)
	  {
		  sprintf((char *)display.f_line, "Gin Tonic");
		  lcd_display(&display);
	  }
	  if(number == 6)
	  {
		  sprintf((char *)display.f_line, "Vodka Cola");
		  lcd_display(&display);
	  }
	  if(number == 7)
	  {
		  sprintf((char *)display.f_line, "Cosmopolitan");
		  lcd_display(&display);
	  }
	  if(number == 8)
	  {
		  sprintf((char *)display.f_line, "Vodka Sunrise");
		  lcd_display(&display);
	  }

  }
  void buttons()		//funkcja odpowiedzialna za obsługę przycisków odpowiedzialnych za wybór drinka
    {

    	//przewijanie w górę
    	if(HAL_GPIO_ReadPin(Up_GPIO_Port, Up_Pin) == 0)
    	{
    		HAL_Delay(time);	// oczekiwanie aż styk przestanie drgać
    		if(HAL_GPIO_ReadPin(Up_GPIO_Port, Up_Pin) == 0)
    		{
    			if(number == 8)	//przeskok z końca na początek
    			{
    				number = 0;
    			}
    			else				// przeskok o jeden dalej
    			{
    				number++;
    			}
    			show();			// wywołanie 'wyświetlania'
    			HAL_Delay(but_delay);	// oczekiwanie na kolejne naciśnięcie przycisku, aby dało sie przewijać 'ciągle' oraz aby dało sie przeczytać obecną opcję (obecnie 500ms)
    		}
    	}
    	//przewijanie w dół
    	if(HAL_GPIO_ReadPin(Down_GPIO_Port, Down_Pin) == 0)
    	{
    		HAL_Delay(time);
    		if(HAL_GPIO_ReadPin(Down_GPIO_Port, Down_Pin) == 0)
    		{
    			if(number == 0)
    			{
    				number = 8;
    			}
    			else
    			{
    				number--;
    			}
    			show();
    			HAL_Delay(but_delay);
    		}
    	}

    	//zatwierdzanie
    	if(HAL_GPIO_ReadPin(Ok_GPIO_Port, Ok_Pin) == 0)
    	{
    		HAL_Delay(time);
    		if(HAL_GPIO_ReadPin(Ok_GPIO_Port, Ok_Pin) == 0)
    		{
    			Your_choice(number);
    		}
    	}
    }

  //
  while (1)
  {
	  buttons();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)	//obsługa przerwania
{
	if(GPIO_Pin == STOP_Pin)
	{
		HAL_GPIO_WritePin(Dioda_GPIO_Port, Dioda_Pin, GPIO_PIN_SET);	//zapalenie diody inforującej o zatrzymaniu programu
		while(HAL_GPIO_ReadPin(GPIOC, STOP_Pin) == GPIO_PIN_RESET)		//zatrzymanie programu do momentu puszczenia przycisku
		{

		}
		HAL_GPIO_WritePin(Dioda_GPIO_Port, Dioda_Pin, GPIO_PIN_RESET);	//zgaszenie diody inforującej o zatrzymaniu programu
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
