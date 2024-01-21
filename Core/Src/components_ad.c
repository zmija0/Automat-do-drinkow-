/*
 * components_ad.c
 *
 *  Created on: Jan 21, 2024
 *      Author: Artur Dębski
 */
#include "components_ad.h"
#include "engines_ad.h"
int next_X;
int next_Y;

void Water(int ml)	//funkcja opisująca położenie wody pobierająca informację o ilości ml którą należy dostarczyć
{
  next_X = 2175;	//współrzędna x opisana w krokach od punktu wyjścia
  next_Y = 2275;	//współrzędna y opisana w krokach od punktu wyjścia
  direction (next_X, next_Y,  ml);	//wywołanie funkcji obsługi ruchu i pobierania płynu z butelki
}
void Wodka(int ml)
{
  next_X = 4675;
  next_Y = 2275;
  direction (next_X, next_Y,  ml);
}
void Fierro(int ml)
{
  next_X = 7175;
  next_Y = 2275;
  direction (next_X, next_Y,  ml);
}
void Gin(int ml)
{
  next_X = 9675;
  next_Y = 2275;
  direction (next_X, next_Y,  ml);
}
void Bianco(int ml)
{
  next_X = 2175;
  next_Y = 4775;
  direction (next_X, next_Y,  ml);
}
void Rum(int ml)
{
  next_X = 4675;
  next_Y = 4775;
  direction (next_X, next_Y,  ml);
}
void Pomarancza(int ml)
{
  next_X = 7175;
  next_Y = 4775;
  direction (next_X, next_Y,  ml);
}
void Jablko(int ml)
{
  next_X = 9675;
  next_Y = 4775;
  direction (next_X, next_Y,  ml);
}
void Limonka(int ml)
{
  next_X = 2175;
  next_Y = 7275;
  direction (next_X, next_Y,  ml);
}
void Granat(int ml)
{
  next_X = 4675;
  next_Y = 7275;
  direction (next_X, next_Y,  ml);
}
void Zurawina(int ml)
{
  next_X = 7175;
  next_Y = 7275;
  direction (next_X, next_Y,  ml);
}
void Cola(int ml)
{
  next_X = 9675;
  next_Y = 7275;
  direction (next_X, next_Y,  ml);
}
void Sprite(int ml)
{
  next_X = 2175;
  next_Y = 9775;
  direction (next_X, next_Y,  ml);
}
void Gazowana(int ml)
{
  next_X = 4675;
  next_Y = 9775;
  direction (next_X, next_Y,  ml);
}
void Tonic(int ml)
{
  next_X = 7175;
  next_Y = 9775;
  direction (next_X, next_Y,  ml);
}
void Malina(int ml)
{
  next_X = 9675;
  next_Y = 9775;
  direction (next_X, next_Y,  ml);
}

