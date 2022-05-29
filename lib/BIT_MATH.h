/*
 * BIT_MATH.h
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define BIT_SET(VAR,BIT)	(VAR)|=(1<<(BIT))
#define BIT_CLEAR(VAR,BIT) 	(VAR)&=~(1<<(BIT))
#define BIT_TOGGLE(VAR,BIT) (VAR)^=(1<<(BIT))
#define BET_GET(VAR,BIT) 	(((VAR)>>(BIT))&1)


#endif /* BIT_MATH_H_ */
