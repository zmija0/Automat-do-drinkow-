/*
 * back_ad.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Artur Dębski
 */
#include "back_ad.h"
#include "gpio.h"
#include "engines_ad.h"

void back_to_start()	//funkcja odpowiedzialna za powrót do pozycji wyjściowej (cofanie każdej osi aż nastąpi załączenie czujnika krańcowego)
{
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET); //odblokowanie sterowników silników
	HAL_GPIO_WritePin(DirX_GPIO_Port, DirX_Pin, GPIO_PIN_RESET); //ustawienie kierunku do pozycji początkowej
	HAL_GPIO_WritePin(DirY_GPIO_Port, DirY_Pin, GPIO_PIN_RESET); //ustawienie kierunku do pozycji początkowej
	HAL_GPIO_WritePin(DirZ_GPIO_Port, DirZ_Pin, GPIO_PIN_RESET); //ustawienie kierunku do pozycji początkowej
	for (;;) //oś Z (najważniejsze aby pierwsze podnieść rurke żeby niczego nie strąciła)
	{
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_RESET);
		HAL_Delay(2);
		if (HAL_GPIO_ReadPin(kZ_GPIO_Port, kZ_Pin) == 0)	//sprawdzanie czujnika krańcowego
		{
			break;
		}
	}
	for (;;) //oś X
	{
		HAL_GPIO_WritePin(StepX_GPIO_Port, StepX_Pin, GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(StepX_GPIO_Port, StepX_Pin, GPIO_PIN_RESET);
		HAL_Delay(2);
		if (HAL_GPIO_ReadPin(kX_GPIO_Port, kX_Pin) == 0)
		{
			break;
		}
	}
	for (;;) //oś Y
	{
		HAL_GPIO_WritePin(StepY_GPIO_Port, StepY_Pin, GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(StepY_GPIO_Port, StepY_Pin, GPIO_PIN_RESET);
		HAL_Delay(2);
		if (HAL_GPIO_ReadPin(kY_GPIO_Port, kY_Pin) == 0)
		{
			break;
		}
	}
	current(0, 0);	// zmiana 'widzianych' koordynatów na początkowe
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);	// zablokowanie sterowników
}



