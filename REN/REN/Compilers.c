/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2023
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************/
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
* File name: compilers.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: May 01 2023
* Professor: Paulo Sousa
* Purpose: This file is the main program of Compilers Project
* Function list: main().
************************************************************
*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: reader > scanner > parser).
 * ............................................................................
 */

/*
***********************************************************
* Function name: main
* Purpose: Main function
* Author: Paulo Sousa
* History/Versions: Ver F22
* Called functions: mainReader(), mainScanner(), mainParser()
* Parameters: Command line arguments - argc, argv
* Return value: Status
* Algorithm: -
*************************************************************
*/

int main(int argc, char** argv) {
	int i;
	printLogo();
	if (DEBUG) {
		for (i = 0; i < argc; ++i)
			printf("argv[%d] = %s\n", i, argv[i]);
	}
	if (argc < 2) {
		printf("%s%c%s%c%s%c%s", "OPTIONS:\n* [",
			PGM_READER, "] - Reader\n* [",
			PGM_SCANNER, "] - Scanner\n* [",
			PGM_PARSER, "] - Parser\n");
		return EXIT_FAILURE;
	}
	ren_char option = argv[1][0];
	switch (option) {
	case PGM_READER:
		printf("%s%c%s", "\n[Option '", PGM_READER, "': Starting READER .....]\n\n");
		mainReader(argc, argv);
		break;
	/* TO_DO: Include later SCANNER (A22) and PARSER (A32) */ 
	case PGM_SCANNER:
		printf("%s%c%s", "\n[Option '", PGM_SCANNER, "': Starting SCANNER .....]\n\n");
		mainReader(argc, argv);
		break;
	case PGM_PARSER:
		printf("%s%c%s", "\n[Option '", PGM_PARSER, "': Starting PARSER .....]\n\n");
		mainReader(argc, argv);
		break;
	default:
		printf("%s%c%s%c%s%c%s", "* OPTIONS:\n- [",
			PGM_READER, "] - Reader\n- [",
			PGM_SCANNER, "] - Scanner\n- [",
			PGM_PARSER, "] - Parser\n");
		break;
	}
	return EXIT_SUCCESS;
}

/*
***********************************************************
* Function name: printLogo
* Purpose: Print Logo
* Author: Paulo Sousa
* History/Versions: Ver S23
* Called functions: -
* Parameters: -
* Return value: (Null)
* Algorithm: -
*************************************************************
*/

/* TO_DO: Update your logo with your own language message */

nonetype printLogo() {
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		"\t=---------------------------------------=\n",
		"\t|  COMPILERS - ALGONQUIN COLLEGE (F23)  |\n",
		"\t=---------------------------------------=\n",
		"\t|              ....                     |\n",
		"\t|          ........::.::::::.           |\n",
		"\t|        .:........::.:^^^~~~:          |\n",
		"\t|        :^^::::::^^^::^!7??7~^.        |\n",
		"\t|       .:^~~^!77777~~7?YY?7??7^.       |\n",
		"\t|       :.^~!??!^::::^^~!?5PY??!~.      |\n",
		"\t|       ~!!7J~.:::^^^^~!!~~?G5J?~       |\n",
		"\t|       :^~?!~7?Y57^^?PP5YJ!J5Y?:       |\n",
		"\t|       .~!!.:^!7!:.:7JYYJ7~7Y7^        |\n",
		"\t|       .~77..    . .~^:^^^~7?:         |\n",
		"\t|       .^!^~:::.:^!7?~^~!77J:          |\n",
		"\t|        ^^!Y~^^^^~?YJ77??7JJ^          |\n",
		"\t|       .^7J?~^~~^~7??7??7JY?~:         |\n",
		"\t|        ::^^~^7?!^~~!7???J?J7~:.       |\n",
		"\t|         ^~~!.^7YPPPP5Y?7J7777~.       |\n",
		"\t|        ..:~..:^!JPP5YJ?!777!^.        |\n",
		"\t| .~?JJJJJJJJJJYYYYYPPPPPPPPPPPP5PPYY~  |\n",
		"\t|  :!Y5GGG.___ YYYYYY__._.PPGGGGGG5!.   |\n",
		"\t|   :!Y5G / __| ___ / _(_)__ _ PGP5.    |\n",
		"\t|    :~75 \\__ \\/ _ \\  _| / _` | 5?.     |\n",
		"\t|     7~7 |___/\\___/_| |_\\__,_| Y5?.    |\n",
		"\t|    .^~!~.....................P5YY7.   |\n",
		"\t|   .:::::::::::::?JJJJYYYYYYYYYJJJJ7.  |\n",
		"\t|                                       |\n",
		"\t=---------------------------------------=\n"
	);
}
