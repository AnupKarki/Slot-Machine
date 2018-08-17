/*
 * supportFunctions.h
 *
 *  Created on: Mar 21, 2017
 *      Author: i_anu
 */

#ifndef SUPPORTFUNCTIONS_H_
#define SUPPORTFUNCTIONS_H_

#include "msp.h"


volatile uint32_t intervalCnt;
volatile uint32_t MCLKfreq, SMCLKfreq;
volatile uint8_t ms_timeout;

void clockInit48MHzXTL(void);
void delayNms(int Counter);


#endif /* SUPPORTFUNCTIONS_H_ */
