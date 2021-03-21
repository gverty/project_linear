/**
*@mainpage
*#
*1. **Tasks**
*
*	- a function that implements the insertion of a substring into a string
*	- function of deleting a substring from a string by initial and final indexes
*	- functions of adding and removing elements from the dynamic array of a given application area
*	- add modular tests that demonstrate the correctness of the developed functions.
*
*# About program
*2. *Description*
*	- The program consists of a structure and has six functions
*@author Kulish P.
*@date 13-mar-2021
*/

/**
*@file main.c
*@author Kulish P.
*@return 0
*@version 1.0
*@date 13-mar-2021
*/
#define _CRT_SECURE_NO_WARNINGS
#include "functionsInitializations.h"
int main(){
	/** @main_str - variable for main text*/
	char main_str[]="abrakadabra";
	/** @main_str_ptr - pointer allocation dynamic memory for @main_str*/
	char *main_str_ptr=(char*)malloc(sizeof(char));
	/** @main_str_ptr - this pointer takes adress of @main_str*/
	main_str_ptr =&main_str;
	
	/** @insert_str - variable for inserting text*/
	char insert_str[]="TEXT";
	/** @insert_str_ptr - pointer allocation dynamic memore for @insert_str*/
	char *insert_str_ptr=(char*)malloc(sizeof(char));
	/** @insert_str_ptr - this pointer takes adress from @insert_str*/
	insert_str_ptr=&insert_str;
	/** @insert_index - variable where need insert text*/
	int insert_index = 4;
	/** @start_index - variable of start index for deleting*/
	int start_index=4;
	/** @end_index - variable of end index for deleting*/
	int end_index=8;
	/** Show string with inserted text*/
	printf("String with inserted text: \n%s\n",insert(main_str_ptr,insert_str_ptr,insert_index));
	/** Show string with reduced text*/
	printf("String with reduced text: \n%s\n",reduce(main_str_ptr,start_index,end_index));
	
	/** @N - variable for size of struct*/
	const int N = 5;
	struct basic_type *sneakers=(struct basic_type*)malloc(sizeof(struct basic_type)*N);
	/** Using function of GetData - filling @sneakers sturct*/
	GetData(sneakers,N);
	/** Using function of ShowData - showing data of @sneakers sturct*/
	ShowData(sneakers,N);
	puts("------");
	add_struct((struct basic_type*)sneakers,N);
	ShowData(sneakers,N+1);
	puts("------");
	/**@struct_to_delete - this variable(for deleting needed number of struct) can be <= than variable N*/
	int struct_to_delete = 1;
	delete_struct((struct basic_type*)sneakers,N,struct_to_delete);
	ShowData(sneakers,N-1);
}


