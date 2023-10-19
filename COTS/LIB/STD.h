#ifndef STD_H
#define STD_H


#define NULL    ((void *)0)



typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;

typedef float              f32;
typedef double             f64;

typedef enum
{
	STD_TYPES_OK,
	STD_TYPES_NOK
}ErrorState;

#endif
