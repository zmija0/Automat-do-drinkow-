/*
 * engines_ad.c
 *
 *  Created on: Jan 20, 2024
 *      Author: Artur Dębski
 */

#include "engines_ad.h"
#include "gpio.h"
#include <stdlib.h>


int step_z = 7200;
int steps;
int step_delay = 2;
int i;
int ms_rain = 0;
int current_X = 0;
int current_Y = 0;


void current(int current_x, int current_y)
{
	current_X = current_x;
	current_Y = current_y;
}

void moveX (int next_x)	//obsługa ruchu w osi x
{
	steps = abs(current_X - next_x);	//obliczenie ilości kroków do miejsca docelowego
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET); //odblokowanie sterowników silników

	for(i = 0; i<steps; i++)	// instrukcja obsługująca zrobienie steps kroków danego silnika
	{	//celowo nie korzystam z PWM 50% ponieważ chcę, aby każda z osi poruszała sie pojedyńczo, oraz aby użytkownik nie mógł nic zrobić w czasie nalewania
		//jest to prostsza opcja aniżeli wyłączanie odczytu przycisków etc
		HAL_GPIO_WritePin(StepX_GPIO_Port, StepX_Pin, GPIO_PIN_SET);
		HAL_Delay(step_delay);
		HAL_GPIO_WritePin(StepX_GPIO_Port, StepX_Pin, GPIO_PIN_RESET);
		HAL_Delay(step_delay);
	}
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET); //zablokowanie sterowników silników aby uniknąć ich grzania
	current_X = next_x;	//zapisanie obecnej pozycji
}

void directionX (int next_x) //ustalanie kierunku ruchu silnika w osi x
{
	if (current_X <= next_x)	//sprawdzenie czy obecne koordynaty (liczba kroków od początku osi) są bliżej niż współrzędne zadane
	{
		HAL_GPIO_WritePin(DirX_GPIO_Port, DirX_Pin, GPIO_PIN_SET);	//ustawienie kierunku ruchu 'od' początku osi za pomocą stanu wysokiego podanego na sterownik
	}
	else
	{
		HAL_GPIO_WritePin(DirX_GPIO_Port, DirX_Pin, GPIO_PIN_RESET);	//ustawienie kierunku 'do' początku osi za pomocą stanu niskiego podanego na sterownik
	}
	moveX(next_x); // wywołanie funkcji obsługi ruchu silnika
}

void moveY (int next_y) //analogicznie jak moveX
{
	steps = abs(current_Y - next_y);
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);

	for(i = 0; i<steps; i++)
	{
		HAL_GPIO_WritePin(StepY_GPIO_Port, StepY_Pin, GPIO_PIN_SET);
		HAL_Delay(step_delay);
		HAL_GPIO_WritePin(StepY_GPIO_Port, StepY_Pin, GPIO_PIN_RESET);
		HAL_Delay(step_delay);
	}

	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET);
	current_Y = next_y;
}

void directionY (int next_y) //ustalanie kierunku ruchu silnika w osi y
{
	if (current_Y <= next_y)
	{
		HAL_GPIO_WritePin(DirY_GPIO_Port, DirY_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(DirY_GPIO_Port, DirY_Pin, GPIO_PIN_RESET);
	}
	moveY(next_y);
}

void directionZ (int ml)
{
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_RESET);	//załączenie sterowników silników
	HAL_GPIO_WritePin(DirZ_GPIO_Port, DirZ_Pin, GPIO_PIN_SET);	//ustawienie kierunku (w dół)
	step_delay = 1;	//przyśpieszenie silników (w tej osi nie ma problemu z prędkością i stabilnością)
	for (i = 0; i<step_z; i++)	//opuszczanie rurki do butelki
	{
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_SET);
		HAL_Delay(step_delay);
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_RESET);
		HAL_Delay(step_delay);
	}
	ms_rain = ml*125;	//przeliczenie ml na ms
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_SET);	//uruchomienie przekaźnika do pompki
	HAL_Delay(ms_rain);	//czas nalewania
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_RESET);	//zatrzymanie nalewania
	HAL_GPIO_WritePin(DirZ_GPIO_Port, DirZ_Pin, GPIO_PIN_RESET);	//zmiana kierunku ruchu (w górę)
	for (i = 0; i<step_z; i++)	//podnoszenie rurki
	{
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_SET);
		HAL_Delay(step_delay);
		HAL_GPIO_WritePin(StepZ_GPIO_Port, StepZ_Pin, GPIO_PIN_RESET);
		HAL_Delay(step_delay);
	}
	step_delay = 2; //ponowne spowolnienie ruchu
	HAL_GPIO_WritePin(Enable_GPIO_Port, Enable_Pin, GPIO_PIN_SET); //ponowne wyłączenie sterowników
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_SET);	//uruchomienie przekaźnika do pompki
	HAL_Delay(3000);	//oczekiwanie 3sek aby z pionowej części rurki zassać płyn żeby nie wyciekał podczas ruchu
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_RESET);	//zatrzymanie nalewania
}

void direction (int next_x, int  next_y, int ml)
{
	directionX(next_x);	//wywołanie funkcji obsługującej kierunek ruchu
	directionY(next_y);
	directionZ(ml);	//wywołanie funkcji zanurzającej rurkę oraz włączającej pompkę
}


