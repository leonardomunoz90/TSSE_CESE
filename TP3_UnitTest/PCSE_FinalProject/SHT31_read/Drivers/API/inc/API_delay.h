/*
 * API_delay.h
 *
 *  Created on: Mar 18, 2023
 *      Author: leonardo
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include "stdint.h"
#include "stdbool.h"

typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
uint32_t GetTick();


#endif /* API_INC_API_DELAY_H_ */
