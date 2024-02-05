/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2023
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
/*

 ````````````````````````````````````````````
 |		RRRRR   	 EEEEE  	 N    N 	|
 |		R    R  	 E      	 NN   N 	|
 |		RRRRR   	 EEEE   	 N N  N 	|
 |		RRRRR   	 EEEE   	 N N  N 	|
 |		R   R   	 E      	 N  N N 	|
 |		R    R  	 EEEEE  	 N    N 	|
 |											|
 ````````````````````````````````````````````

*/


/*
************************************************************
* File name: Compilers.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file defines the functions called by main function.
* Function list: mainReader(), mainScanner(), mainParser().
*************************************************************/

#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: reader > scanner > parser).
 * ............................................................................
 */

/* TO_DO: Adjust your language (cannot be "Sofia") */

/* Language name */
#define STR_LANGNAME	"REN"

/* Logical constants - adapt for your language */
#define True  1
#define False 0

/*
------------------------------------------------------------
Data types definitions
NOTE: Some types may not be directly used by your language,
		but they can be necessary for conversions.
------------------------------------------------------------
*/


/* TO_DO: Define your typedefs */
typedef char			ren_char;
typedef char*           str;


typedef void			nonetype;

typedef unsigned char	ren_boln;
typedef unsigned char	ren_byte;

typedef long			ren_long;
typedef double			ren_doub;

/*
------------------------------------------------------------
Programs:
1: Reader - invokes MainReader code
2: Scanner - invokes MainScanner code
3: Parser - invokes MainParser code
------------------------------------------------------------
*/
enum PROGRAMS {
	PGM_READER	= 'r',
	PGM_SCANNER = 's',
	PGM_PARSER	= 'p'
};

/*
------------------------------------------------------------
Main functions signatures
(Code will be updated during next assignments)
------------------------------------------------------------
*/
int mainReader(int argc, str* argv);

/* 
TO_DO: Include later mainScaner (A22) and mainParser (A32)
*/
int mainScanner(int argc, str* argv);
int mainParser(int arec, str* argv);

nonetype printLogo();

#endif
