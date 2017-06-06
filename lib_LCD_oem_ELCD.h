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
	* @param pin_tx par defaut p13
    */
	LCD_OEM(PinName pin_tx = p13);

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
    * @param nb la variable à afficher
    * @returns printf return
    */
    int print(int nb);
	int print(unsigned int nb);
	int print(short nb);
	int print(unsigned short nb);
	int print(long long nb);
	int print(unsigned long long nb);
	int print(float nb);
	int print(double nb);
	int print(char c);
	int print(char *s);
	
	/** affiche une chaine formaté sur l'afficheur
    *
    * @param format la chaine de format à afficher
    * @param ... les arguments à afficher
    * @returns printf return
    */
	int print(const char *format, ... );
    
private :
    void init(void);
    void putnc(char *s, int n);
    void X_move_position(int n);
    int X_position_cursor;
    int Y_position_cursor;
};

#endif
