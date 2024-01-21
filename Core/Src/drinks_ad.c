/*
 * drinks_ad.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Artur Dębski
 */

#include "gpio.h"
#include "components_ad.h"
#include "back_ad.h"


void After_Raining()
{
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_SET);
	HAL_Delay(15000);
	HAL_GPIO_WritePin(Woda_GPIO_Port, Woda_Pin, GPIO_PIN_RESET);
	back_to_start();
}
void Cleaning()
{
	Water(100);
	After_Raining();
}
void Californication()
{
  Wodka(20);
  Gin(20);
  Rum(20);
  Limonka(40);
  Pomarancza(80);
  After_Raining();
}

void Sex_on_the_beach()
{
  Wodka(40);
  Pomarancza(40);
  Zurawina(40);
  After_Raining();
}

void Cuba_Libre()
{
  Rum(50);
  Limonka(30);
  Cola(120);
  After_Raining();
}

void Mohito()
{
  Rum(40);
  Limonka(80);
  Gazowana(60);
  After_Raining();
}

void Gin_Tonic()
{
  Gin(50);
  Tonic(150);
  After_Raining();
}

void Wodka_Cola()
{
  Wodka(50);
  Cola(150);
  After_Raining();
}

void Cosmopolitan()
{
  Wodka(40);
  Pomarancza(20);
  Limonka(20);
  Zurawina(40);
  After_Raining();
}

void Vodka_Sunrise()
{
  Wodka(50);
  Malina(30);
  Pomarancza(150);
  After_Raining();
}



