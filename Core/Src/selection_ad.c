/*
 * selection_ad.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Artur Dębski
 */

#include "selection_ad.h"
#include "drinks_ad.h"
#include "gpio.h"

void Your_choice(int number)
{
	if (number == 0)
	{
		Cleaning();
	}
	if (number == 1)
	{
		Californication();
	}
	if (number == 2)
	{
		Sex_on_the_beach();
	}
	if (number == 3)
	{
		Cuba_Libre();
	}
	if (number == 4)
	{
		Mohito();
	}
	if (number == 5)
	{
		Gin_Tonic();
	}
	if (number == 6)
	{
		Wodka_Cola();
	}
	if (number == 7)
	{
		Cosmopolitan();
	}
	if (number == 8)
	{
		Vodka_Sunrise();
	}
}

