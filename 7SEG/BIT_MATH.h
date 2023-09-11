#ifndef BIT_MATH_H
#define BIT_MATH_H

// Functions Like Macro To Manipulate Over Specific Bit 
#define     SET_BIT(REG, BIT)         ((REG) |= (1 << BIT))         
#define     CLR_BIT(REG, BIT)         ((REG) &= (~(1 << BIT)))
#define     GET_BIT(REG, BIT)         ((REG) >> BIT) & 0x01)
#define     TOG_BIT(REG, BIT)        ((REG) ^= (1 << BIT))

#endif
