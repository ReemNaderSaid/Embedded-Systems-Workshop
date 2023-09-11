/*****************************************************/
/************ Author: REEM NADER SAID*****************/
/************ Date: 30 Aug 2023***********************/
/************ Version: 0.1****************************/
/************ File Name: BIT_MATH.h *****************/
/*****************************************************/

#ifndef  BIT_MATH__H
#define  BIT_MATH__H

#define set_bit(reg,bit_no)     reg |=(1<<bit_no)
#define clr_bit(reg,bit_no)     reg &= ~(1<<bit_no)
#define toggle_bit(reg,bit_no)  reg ^=(1<<bit_no)
#define get_bit(reg,bit_no)     (reg &=(1<<bit_no))>> bit_no








#endif /*BIT_MATH__H */