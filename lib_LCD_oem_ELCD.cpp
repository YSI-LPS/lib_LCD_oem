/** LCD oem ELCD class
*
* @purpose       library for oem ELCD
*
* Utilisée pour écrire sur l'afficheur oem ELCD 4x20.
*
* http://www.lextronic.fr/P764-afficheur-4-x-20-caracteres-retro-eclaire-vert.html
*
* Copyright (c) 2014, cstyles (http://mbed.org)
*
* Exemple:
* @code
* #include "mbed.h"
* #include "lib_LCD_oem_ELCD.h"
*
* LCD_OEM LCD;
* //LCD_OEM LCD(p13);	 //Tx
* 
* int main()
* {
*	  while(1)
*	  {
*		  for(int i = 0; i < 9999; i++)
*         {
*             LCD.clear();
*             LCD.print(i);
*             wait(0.25);
*         }
*     }
* }
* @endcode
* @file          lib_LCD_oem_ELDC.cpp 
* @date          Jan 2014
* @author        Yannic Simon
*/

#include "lib_LCD_oem_ELCD.h"

#define lcd_soft_boot	0xA0
#define lcd_cursor_pos	0xA1
#define lcd_display		0xA2	
#define lcd_cursor		0xA3
#define lcd_redef_print	0xA4
#define lcd_redef		0xA5


LCD_OEM::LCD_OEM(PinName pin_tx) : Serial(pin_tx, NC)
{
	init();
	clear();
}

void LCD_OEM::init(void)
{
	LCD_OEM::baud(19200);
	LCD_OEM::putc(lcd_soft_boot);
	wait_ms(50);
}

void LCD_OEM::clear(void)
{
	LCD_OEM::printf("%c%c", lcd_cursor, 0x01);
	X_position_cursor = 0;
	Y_position_cursor = 0;
	wait_ms(2);
}

void LCD_OEM::turn_off_cursor(void)
{
	LCD_OEM::printf("%c%c", lcd_cursor, 0x0C);
}

void LCD_OEM::turn_on_cursor(void)
{
	LCD_OEM::printf("%c%c", lcd_cursor, 0x0E);
}

void LCD_OEM::shift_line_cursor(void)
{
	if(Y_position_cursor < 3)	Y_position_cursor++;
	LCD_OEM::printf("%c%c%c", lcd_cursor_pos, 0, Y_position_cursor);
}

void LCD_OEM::set_position_cursor(int X)
{
	if(X < 0)		X = 0;
	else if(X > 19)	X = 19;
	X_position_cursor = X;
	LCD_OEM::printf("%c%c%c", lcd_cursor_pos, X_position_cursor, Y_position_cursor);
}

void LCD_OEM::set_position_cursor(int X, int Y)
{
	if(X < 0)		X = 0;
	else if(X > 19)	X = 19;
	if(Y < 0)		Y = 0;
	else if(Y > 3)	Y = 3;
	X_position_cursor = X;
	Y_position_cursor = Y;
	LCD_OEM::printf("%c%c%c", lcd_cursor_pos, X_position_cursor, Y_position_cursor);
}

void LCD_OEM::X_move_position(int n)
{
	X_position_cursor += n;
	while(X_position_cursor > 19)
	{
		X_position_cursor -= 20;
		Y_position_cursor += 2;
		if(Y_position_cursor > 4)	Y_position_cursor -= Y_position_cursor;
		else if(Y_position_cursor == 4)	Y_position_cursor = 1;
	}
}

int LCD_OEM::get_X_position_cursor(void)
{
	return X_position_cursor;
}

int LCD_OEM::get_Y_position_cursor(void)
{
	return Y_position_cursor;
}

void LCD_OEM::define_and_print_caractere(char c, char l1, char l2, char l3, char l4, char l5, char l6, char l7, char l8)
{
	print((char)c);
	define_caractere(c, l1, l2, l3, l4, l5, l6, l7, l8);
}

void LCD_OEM::define_caractere(char c, char l1, char l2, char l3, char l4, char l5, char l6, char l7, char l8)
{
	char data[]={lcd_redef,c,l1,l2,l3,l4,l5,l6,l7,l8};
	if(c > 7 && c < 16)
	{
		for(int i=0;i<10;i++)
		{
			LCD_OEM::putc(data[i]);
			wait_ms(1);
		}
	}
	set_position_cursor(X_position_cursor, Y_position_cursor);
}

int LCD_OEM::print(char c)
{
	int n = LCD_OEM::printf("%c%c%c", lcd_display, c, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(short nb)
{
	int n = LCD_OEM::printf("%c%d%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(unsigned short nb)
{
	int n = LCD_OEM::printf("%c%u%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(int nb)
{
	int n = LCD_OEM::printf("%c%d%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(unsigned int nb)
{
	int n = LCD_OEM::printf("%c%u%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(long long nb)
{
	int n = LCD_OEM::printf("%c%lld%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(unsigned long long nb)
{
	int n = LCD_OEM::printf("%c%llu%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(float nb)
{
	int n = LCD_OEM::printf("%c%f%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(double nb)
{
	int n = LCD_OEM::printf("%c%lf%c", lcd_display, nb, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(char *s)
{
	int n = LCD_OEM::printf("%c%s%c", lcd_display, s, 0) - 2;
	X_move_position(n);
	return n;
}

int LCD_OEM::print(const char *format, ... )
{
    char buffer[256]={0x00};
    va_list args;
    va_start(args, format);
    vsnprintf(buffer,256,format,args);
    va_end(args);
    int n = LCD_OEM::printf("%c%s%c", lcd_display, buffer, 0) - 2;
	X_move_position(n);
	return n;
}

void LCD_OEM::putnc(char *s, int n)
{
    for(int i = 0; i < n; i++)
    {
    	LCD_OEM::putc(s[i]);
    }
    X_move_position(n);
}
