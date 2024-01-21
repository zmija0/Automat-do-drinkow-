/*
 * engines_ad.h
 *
 *  Created on: Jan 21, 2024
 *      Author: Artur Dębski
 */

#ifndef INC_ENGINES_AD_H_
#define INC_ENGINES_AD_H_

void current(int current_x, int current_y);
void moveX (int next_x);
void directionX (int next_x);
void moveY (int next_y);
void directionY (int next_y);
void directionZ (int ml);
void direction (int next_x, int  next_y, int ml);

#endif /* INC_ENGINES_AD_H_ */
