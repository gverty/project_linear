/**
*@file test.c
*@brief File with realizations all functions for testing main functions.
*
*@author Kulish P.
*@date 13-mar-2021
*@version 1.0
*/
#include "functionsInitializations.h"
void test_insertFunction(){
	char *s1 = (char*)malloc(sizeof(char));
	char *s2 = (char*)malloc(sizeof(char));
	s1 = "abrssssakadabra";
	s2 = "TEXT";
	if (strcmp(insert(s1,s2,4),"abraTEXTkadabra") == NULL ){
		puts("\nTesting _insert_  was successful\n");
	}
	else{
		printf("\Testing _insert_ was failed\n");
	}
}

void test_reducingFunction(){
	char *s1 =(char*)malloc(sizeof(char));
	s1 = "abrakadabra";
	if(strcmp(reduce(s1,4,8),"abrara") == NULL){
		puts("Testing _reduce_ was successful\n");
		}
	else{
		puts("Testing _reduce was failed\n");
	}
}
void test_add_struct(){
	struct basic_type *test_sneakers = (struct basic_type*)malloc(sizeof(struct basic_type));
	int n = 3;
	int price_test = 0;
	for(int i = 0;i<n;i++){
		test_sneakers[i].price = 4;
		}
	add_struct(test_sneakers,n);
	for(int i = 0;i<n+1;i++){
		price_test += test_sneakers[i].price;
		}
	
	if(price_test = 16){
		puts("\Testing _add_struct_ was successful\n");
		}
	else{
		puts("\Testing _add_struct_ was failed\n");
		}
}

void test_delete_struct(){
	struct basic_type *test_sneakers = (struct basic_type*)malloc(sizeof(struct basic_type));
	int n = 3;
	int struct_to_delete = 2;
	
	for(int i = 0;i<n;i++){
		test_sneakers[i].price = 4;
	}
	
	delete_struct(test_sneakers,n,struct_to_delete);
	
	if (test_sneakers[struct_to_delete].price == 0) {
		puts("\Testing _delete_struct_ was done successful\n");
		}
	else{
		puts("\Testing _delete_struct_ was failed\n");
	}
}

int main(){
	test_insertFunction();
	test_reducingFunction();
	
	test_add_struct();
	test_delete_struct();
}
