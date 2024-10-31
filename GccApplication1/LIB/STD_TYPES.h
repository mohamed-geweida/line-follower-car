/*
 * STD_TYPES.h
 *
 * Author: 0110
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;    /**< unsigned 8-bit integer */
typedef unsigned short u16;   /**< unsigned 16-bit integer */
typedef unsigned long u32;    /**< unsigned 32-bit integer */

typedef signed char s8;       /**< signed 8-bit integer */
typedef signed short s16;     /**< signed 16-bit integer */
typedef signed long s32;      /**< signed 32-bit integer */

typedef float f32;            /**< single-precision floating-point number (32-bit) */
typedef double f64;           /**< double-precision floating-point number (64-bit) */

#define ERROR 0
#define NO_ERROR 1

#define NULL ((void *)0)

#endif /* STD_TYPES_H_ */