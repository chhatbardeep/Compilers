/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2023
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
=---------------------------------------=
|  COMPILERS - ALGONQUIN COLLEGE (W24)  |
=---------------------------------------=

*/
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
* File name: Reader.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A12.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file is the main header for Reader (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * Please check the "TODO" labels to develop your activity.
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#define READER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer reader) */
enum READER_MODE {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls (not need to change) */
#define READER_ERROR		(-1)						/* General error message */
#define READER_TERMINATOR	'\0'							/* General EOF */

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* You should add your own constant definitions here */
#define READER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

#define READER_DEFAULT_SIZE			250		/* default initial buffer reader capacity */
#define READER_DEFAULT_INCREMENT	10		/* default increment factor */

/* Add your bit-masks constant definitions here - Defined for BOA */
/* BITS                                (7654.3210) */
#define READER_DEFAULT_FLAG 0x00 	/* (0000.0000)_2 = (000)_10 */
/* TO_DO: BIT 3: END = End of buffer flag */
/* TO_DO: BIT 2: REL = Rellocation memory flag */
/* TO_DO: BIT 1: EMP = Buffer empty flag */
/* TO_DO: BIT 0: FUL = Buffer full flag */

#define SET_FUL 0x01 /*0000.0001*/
#define RESET_FUL 0xFE /*1111.1110*/
#define CHECK_FUL SET_FUL

#define SET_EMP 0x02 /*0000.0010*/
#define RESET_EMP 0xFD /*1111.1101*/
#define CHECK_EMP SET_EMP

#define SET_REL 0x04 /*0000.0100*/
#define RESET_REL 0xFB /*1111.1011*/
#define CHECK_REL SET_REL

#define SET_END 0x08 /*0000.1000*/
#define RESET_END 0xF7 /*1111.0111*/
#define CHECK_END SET_END


#define NCHAR				128			/* Chars from 0 to 127 */

#define CHARSEOF			(-1)		/* EOF Code for Reader */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (SOFIA) .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct position {
	int mark;			/* the offset to the mark position (in chars) */
	int read;			/* the offset to the get a char position (in chars) */
	int wrte;			/* the offset to the add chars (in chars) */
} Position;

/* Buffer structure */
typedef struct bufferReader {
	str	content;			/* pointer to the beginning of character array (character buffer) */
	int		size;				/* current dynamic memory size (in bytes) allocated to character buffer */
	int		increment;			/* character array increment factor */
	int		mode;				/* operational mode indicator */
	ren_byte		flags;				/* contains character array reallocation flag and end-of-buffer flag */
	Position		position;				/* Offset / position field */
	int		histogram[NCHAR];	/* Statistics of chars */
	int		numReaderErrors;	/* Number of errors from Reader */
} Buffer, *BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer	readerCreate		(int, int, int);
BufferPointer	readerAddChar		(BufferPointer const, ren_char);
ren_boln		readerClear		    (BufferPointer const);
ren_boln		readerFree		    (BufferPointer const);
ren_boln		readerIsFull		(BufferPointer const);
ren_boln		readerIsEmpty		(BufferPointer const);
ren_boln		readerSetMark		(BufferPointer const, int);
int		readerPrint		    (BufferPointer const);
int		readerLoad			(BufferPointer const, FILE* const);
ren_boln		readerRecover		(BufferPointer const);
ren_boln		readerRetract		(BufferPointer const);
ren_boln		readerRestore		(BufferPointer const);
/* Getters */
ren_char		readerGetChar		(BufferPointer const);
str	readerGetContent	(BufferPointer const, int);
int		readerGetPosRead	(BufferPointer const);
int		readerGetPosWrte	(BufferPointer const);
int		readerGetPosMark	(BufferPointer const);
int		readerGetSize		(BufferPointer const);
int		readerGetInc		(BufferPointer const);
int		readerGetMode		(BufferPointer const);
ren_byte		readerGetFlags		(BufferPointer const);
nonetype		readerPrintStat		(BufferPointer const);
int		readerNumErrors		(BufferPointer const);

#endif
