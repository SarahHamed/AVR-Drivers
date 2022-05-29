/*
 * LCD_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Administrator
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

//updated Dec31
/*
//Return Home and Clear display
#define LCD_CLRDISP 	0X01
#define LCD_RETHOME 	0X02
//CURSOR MOVE
#define LCD_CURSOR_LFT	0X10
#define LCD_CURSOR_RGHT	0X14
//DISPLAY MOVE
#define LCD_DISP_LFT	0X18
#define LCD_DISP_RGHT	0X1C
#define LCD_CURSOR_ON	0x0f
//CURSOR ON/OFF
#define LCD_CURSOR_OFF	0x0C
#define LCD_CURSOR_ON	0x0f
//DISPLAY MOVE
#define LCD_INCREMENT_CURSOR 0X06
#define LCD_DECREMENT_CURSOR 0X04

*/
void LCD_voidWriteCommand(u8 u8Command_Cpy);
void LCD_voidWriteData(u8 u8Data_Cpy);
void LCD_voidInitialize(void);
void LCD_voidWriteString(u8 *pu8String_cpy,u8 size);
void LCD_voidGoToXY(u8 pos_x,u8 pos_y);


#endif /* LCD_INTERFACE_H_ */
