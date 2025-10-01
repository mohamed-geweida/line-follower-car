#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var, bitno) ((var) |= (1 << (bitno)))
#define CLR_BIT(var, bitno) ((var) &= ~(1 << (bitno)))
#define TOG_BIT(var, bitno) ((var) ^= (1 << (bitno)))
#define GET_BIT(var, bitno) (((var) >> (bitno)) & 0x01)

#endif /* BIT_MATH_H_ */

