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
* LCD_OEM LCD(p13);	 //Tx
* 
* int main()
* {
*   while(1)
*   {
*       for(int i = 0; i < 9999; i++)
*       {
*           LCD.clear();
*           LCD.print(i);
*           wait(0.25);
*       }
*   }
* }
* @endcode
* @file          lib_LCD_oem_ELDC.h 
* @date          Jan 2014
* @author        Yannic Simon
*/

#ifndef DEF_lib_LCD_OEM_ELCD_H
#define DEF_lib_LCD_OEM_ELCD_H

#include "mbed.h"
#include <cstdarg>

/** LCD_OEM class
 */
class LCD_OEM : public Serial
{
public:
	/** Creer une instance LCD_OEM
	*
	* @param pin_tx par exemple p13
    */
	LCD_OEM(PinName pin_tx);

	/** Efface l'afficheur et renvoie le curseur en position X = 0 et Y = 0
	*
	* @param aucun
	* @returns aucun
	*/
	void clear(void);
	
	/** positionne le curseur sur la ligne
	*
	* @param X est la position sur la ligne (0 à 19)
	* @returns aucun
	*/
	void set_position_cursor(int X);
	
	/** positionne le curseur horizontalement et verticalement
	*
	* @param X est la position sur la ligne (0 à 19)
	* Y est la position sur la colone (0 à 3)
	* @returns aucun
	*/
	void set_position_cursor(int X, int Y);
	
	/** renvoie la position horizontale du curseur
	*
	* @param aucun
	* @returns X est la position sur la ligne (0 à 19)
	*/
	int get_X_position_cursor(void);
	
	/** renvoie la position verticale du curseur
	*
	* @param aucun
	* @returns Y est la position sur la colone (0 à 3)
	*/
	int get_Y_position_cursor(void);
	
	/** positionne le curseur à la ligne suivante
	*
	* @param aucun
	* @returns aucun
	*/
	void shift_line_cursor(void);
	
	/** active l'affichage du curseur
	*
	* @param aucun
	* @returns aucun
	*/
	void turn_on_cursor(void);
	
	/** désactive l'affichage du curseur
	*
	* @param aucun
	* @returns aucun
	*/
	void turn_off_cursor(void);
	
	/** redéfinit un caractère de 5x8 pixels et l'affiche
	*
	* @param c est le caractère à redéfinir (8 à 15)
	* l1 à l8 sont les lignes du caractère à redéfinir pixel par pixel et correspond à la somme des valeurs des pixels sur une chaque ligne
	* le pixel le plus à gauche est le poids fort correspondant à la valeur 16
	* le pixel le plus à droite est le poids faible correspondant à la valeur 1
	* @returns aucun
	*/
	void define_and_print_caractere(char c, char l1, char l2, char l3, char l4, char l5, char l6, char l7, char l8);
	
	/** redéfinit un caractère de 5x8 pixels et l'affiche
	*
	* @param c est le caractère à redéfinir (8 à 15)
	* l1 à l8 sont les lignes du caractère à redéfinir pixel par pixel et correspond à la somme des valeurs des pixels sur une chaque ligne
	* le pixel le plus à gauche est le poids fort correspondant à la valeur 16
	* le pixel le plus à droite est le poids faible correspondant à la valeur 1
	* @returns aucun
	*/
	void define_caractere(char c, char l1, char l2, char l3, char l4, char l5, char l6, char l7, char l8);
	
	/** affiche la variable sur l'afficheur
    *
    * @param s la chaine de caractère à afficher
    * @param ... les arguments à afficher
    * @returns aucun
    */
	void print(const char *s, ... );
	void print(char *s);
	void print(char c);
    void print(char c1, char c2);
    void print(char c1, char c2, char c3);
	void print(short nb);
	void print(unsigned short nb);
	void print(int nb);
	void print(unsigned int nb);
	void print(long long nb);
	void print(unsigned long long nb);
	void print(float nb);
	void print(double nb);
    
    /*void print(char *s, short nb);
    void print(char *s, short nb1, short nb2);
    void print(char *s, short nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, short nb2);
    void print(char *s, short nb1, int nb2);
    void print(char *s, int nb1, short nb2);
    void print(char *s, short nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, short nb2);
    void print(char *s, short nb1, long long nb2);
    void print(char *s, long long nb1, short nb2);
    void print(char *s, short nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, short nb2);
    void print(char *s, short nb1, float nb2);
    void print(char *s, float nb1, short nb2);
    void print(char *s, short nb1, double nb2);
    void print(char *s, double nb1, short nb2);
    void print(char *s, short nb1, short nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, unsigned short nb3);
    void print(char *s, short nb1, unsigned short nb2, short nb3);
    void print(char *s, short nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, short nb2, short nb3);
    void print(char *s, unsigned short nb1, short nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, unsigned short nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, int nb3);
    void print(char *s, short nb1, int nb2, short nb3);
    void print(char *s, short nb1, int nb2, int nb3);
    void print(char *s, int nb1, short nb2, short nb3);
    void print(char *s, int nb1, short nb2, int nb3);
    void print(char *s, int nb1, int nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, unsigned int nb3);
    void print(char *s, short nb1, unsigned int nb2, short nb3);
    void print(char *s, short nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, short nb2, short nb3);
    void print(char *s, unsigned int nb1, short nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, unsigned int nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, long long nb3);
    void print(char *s, short nb1, long long nb2, short nb3);
    void print(char *s, short nb1, long long nb2, long long nb3);
    void print(char *s, long long nb1, short nb2, short nb3);
    void print(char *s, long long nb1, short nb2, long long nb3);
    void print(char *s, long long nb1, long long nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, unsigned long long nb3);
    void print(char *s, short nb1, unsigned long long nb2, short nb3);
    void print(char *s, short nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, short nb2, short nb3);
    void print(char *s, unsigned long long nb1, short nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, float nb3);
    void print(char *s, short nb1, float nb2, short nb3);
    void print(char *s, short nb1, float nb2, float nb3);
    void print(char *s, float nb1, short nb2, short nb3);
    void print(char *s, float nb1, short nb2, float nb3);
    void print(char *s, float nb1, float nb2, short nb3);
    
    void print(char *s, short nb1, short nb2, double nb3);
    void print(char *s, short nb1, double nb2, short nb3);
    void print(char *s, short nb1, double nb2, double nb3);
    void print(char *s, double nb1, short nb2, short nb3);
    void print(char *s, double nb1, short nb2, double nb3);
    void print(char *s, double nb1, double nb2, short nb3);

    
    
    void print(char *s, unsigned short nb);
    void print(char *s, unsigned short nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, int nb2);
    void print(char *s, int nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, long long nb2);
    void print(char *s, long long nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, float nb2);
    void print(char *s, float nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, double nb2);
    void print(char *s, double nb1, unsigned short nb2);
    void print(char *s, unsigned short nb1, unsigned short nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, int nb3);
    void print(char *s, unsigned short nb1, int nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, int nb2, int nb3);
    void print(char *s, int nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, int nb1, unsigned short nb2, int nb3);
    void print(char *s, int nb1, int nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, unsigned int nb3);
    void print(char *s, unsigned short nb1, unsigned int nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, unsigned int nb1, unsigned short nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, unsigned int nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, long long nb3);
    void print(char *s, unsigned short nb1, long long nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, long long nb2, long long nb3);
    void print(char *s, long long nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, long long nb1, unsigned short nb2, long long nb3);
    void print(char *s, long long nb1, long long nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, unsigned long long nb3);
    void print(char *s, unsigned short nb1, unsigned long long nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, unsigned long long nb1, unsigned short nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, float nb3);
    void print(char *s, unsigned short nb1, float nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, float nb2, float nb3);
    void print(char *s, float nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, float nb1, unsigned short nb2, float nb3);
    void print(char *s, float nb1, float nb2, unsigned short nb3);
    
    void print(char *s, unsigned short nb1, unsigned short nb2, double nb3);
    void print(char *s, unsigned short nb1, double nb2, unsigned short nb3);
    void print(char *s, unsigned short nb1, double nb2, double nb3);
    void print(char *s, double nb1, unsigned short nb2, unsigned short nb3);
    void print(char *s, double nb1, unsigned short nb2, double nb3);
    void print(char *s, double nb1, double nb2, unsigned short nb3);
    
 
    
    void print(char *s, int nb);
    void print(char *s, int nb1, int nb2);
    void print(char *s, int nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, int nb2);
    void print(char *s, int nb1, long long nb2);
    void print(char *s, long long nb1, int nb2);
    void print(char *s, int nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, int nb2);
    void print(char *s, int nb1, float nb2);
    void print(char *s, float nb1, int nb2);
    void print(char *s, int nb1, double nb2);
    void print(char *s, double nb1, int nb2);
    void print(char *s, int nb1, int nb2, int nb3);
    
    void print(char *s, int nb1, int nb2, unsigned int nb3);
    void print(char *s, int nb1, unsigned int nb2, int nb3);
    void print(char *s, int nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, int nb2, int nb3);
    void print(char *s, unsigned int nb1, int nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, unsigned int nb2, int nb3);
    
    void print(char *s, int nb1, int nb2, long long nb3);
    void print(char *s, int nb1, long long nb2, int nb3);
    void print(char *s, int nb1, long long nb2, long long nb3);
    void print(char *s, long long nb1, int nb2, int nb3);
    void print(char *s, long long nb1, int nb2, long long nb3);
    void print(char *s, long long nb1, long long nb2, int nb3);
    
    void print(char *s, int nb1, int nb2, unsigned long long nb3);
    void print(char *s, int nb1, unsigned long long nb2, int nb3);
    void print(char *s, int nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, int nb2, int nb3);
    void print(char *s, unsigned long long nb1, int nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, int nb3);
    
    void print(char *s, int nb1, int nb2, float nb3);
    void print(char *s, int nb1, float nb2, int nb3);
    void print(char *s, int nb1, float nb2, float nb3);
    void print(char *s, float nb1, int nb2, int nb3);
    void print(char *s, float nb1, int nb2, float nb3);
    void print(char *s, float nb1, float nb2, int nb3);
    
    void print(char *s, int nb1, int nb2, double nb3);
    void print(char *s, int nb1, double nb2, int nb3);
    void print(char *s, int nb1, double nb2, double nb3);
    void print(char *s, double nb1, int nb2, int nb3);
    void print(char *s, double nb1, int nb2, double nb3);
    void print(char *s, double nb1, double nb2, int nb3);
    
    
    void print(char *s, unsigned int nb);
    void print(char *s, unsigned int nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, long long nb2);
    void print(char *s, long long nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, float nb2);
    void print(char *s, float nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, double nb2);
    void print(char *s, double nb1, unsigned int nb2);
    void print(char *s, unsigned int nb1, unsigned int nb2, unsigned int nb3);
    
    void print(char *s, unsigned int nb1, unsigned int nb2, long long nb3);
    void print(char *s, unsigned int nb1, long long nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, long long nb2, long long nb3);
    void print(char *s, long long nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, long long nb1, unsigned int nb2, long long nb3);
    void print(char *s, long long nb1, long long nb2, unsigned int nb3);
    
    void print(char *s, unsigned int nb1, unsigned int nb2, unsigned long long nb3);
    void print(char *s, unsigned int nb1, unsigned long long nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, unsigned long long nb1, unsigned int nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, unsigned int nb3);
    
    void print(char *s, unsigned int nb1, unsigned int nb2, float nb3);
    void print(char *s, unsigned int nb1, float nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, float nb2, float nb3);
    void print(char *s, float nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, float nb1, unsigned int nb2, float nb3);
    void print(char *s, float nb1, float nb2, unsigned int nb3);
    
    void print(char *s, unsigned int nb1, unsigned int nb2, double nb3);
    void print(char *s, unsigned int nb1, double nb2, unsigned int nb3);
    void print(char *s, unsigned int nb1, double nb2, double nb3);
    void print(char *s, double nb1, unsigned int nb2, unsigned int nb3);
    void print(char *s, double nb1, unsigned int nb2, double nb3);
    void print(char *s, double nb1, double nb2, unsigned int nb3);
    
    
    void print(char *s, long long nb);
    void print(char *s, long long nb1, long long nb2);
    void print(char *s, long long nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, long long nb2);
    void print(char *s, long long nb1, float nb2);
    void print(char *s, float nb1, long long nb2);
    void print(char *s, long long nb1, double nb2);
    void print(char *s, double nb1, long long nb2);
    void print(char *s, long long nb1, long long nb2, long long nb3);
    
    void print(char *s, long long nb1, long long nb2, unsigned long long nb3);
    void print(char *s, long long nb1, unsigned long long nb2, long long nb3);
    void print(char *s, long long nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, long long nb2, long long nb3);
    void print(char *s, unsigned long long nb1, long long nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, long long nb3);
    
    void print(char *s, long long nb1, long long nb2, float nb3);
    void print(char *s, long long nb1, float nb2, long long nb3);
    void print(char *s, long long nb1, float nb2, float nb3);
    void print(char *s, float nb1, long long nb2, long long nb3);
    void print(char *s, float nb1, long long nb2, float nb3);
    void print(char *s, float nb1, float nb2, long long nb3);
    
    void print(char *s, long long nb1, long long nb2, double nb3);
    void print(char *s, long long nb1, double nb2, long long nb3);
    void print(char *s, long long nb1, double nb2, double nb3);
    void print(char *s, double nb1, long long nb2, long long nb3);
    void print(char *s, double nb1, long long nb2, double nb3);
    void print(char *s, double nb1, double nb2, long long nb3);
    
    
    void print(char *s, unsigned long long nb);
    void print(char *s, unsigned long long nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, float nb2);
    void print(char *s, float nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, double nb2);
    void print(char *s, double nb1, unsigned long long nb2);
    void print(char *s, unsigned long long nb1, unsigned long long nb2, unsigned long long nb3);
    
    void print(char *s, unsigned long long nb1, unsigned long long nb2, float nb3);
    void print(char *s, unsigned long long nb1, float nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, float nb2, float nb3);
    void print(char *s, float nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, float nb1, unsigned long long nb2, float nb3);
    void print(char *s, float nb1, float nb2, unsigned long long nb3);
    
    void print(char *s, unsigned long long nb1, unsigned long long nb2, double nb3);
    void print(char *s, unsigned long long nb1, double nb2, unsigned long long nb3);
    void print(char *s, unsigned long long nb1, double nb2, double nb3);
    void print(char *s, double nb1, unsigned long long nb2, unsigned long long nb3);
    void print(char *s, double nb1, unsigned long long nb2, double nb3);
    void print(char *s, double nb1, double nb2, unsigned long long nb3);
    
    
    void print(char *s, float nb);
    void print(char *s, float nb1, float nb2);
    void print(char *s, float nb1, double nb2);
    void print(char *s, double nb1, float nb2);
    void print(char *s, float nb1, float nb2, float nb3);
    
    void print(char *s, float nb1, float nb2, double nb3);
    void print(char *s, float nb1, double nb2, float nb3);
    void print(char *s, float nb1, double nb2, double nb3);
    void print(char *s, double nb1, float nb2, float nb3);
    void print(char *s, double nb1, float nb2, double nb3);
    void print(char *s, double nb1, double nb2, float nb3);
    
    
    void print(char *s, double nb);
    void print(char *s, double nb1, double nb2);
    void print(char *s, double nb1, double nb2, double nb3);*/
    
    
private :
    void init(void);
    void putnc(char *s, int n);
    void X_move_position(int n);
    int X_position_cursor;
    int Y_position_cursor;
};

#endif
