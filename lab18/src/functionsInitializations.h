#ifndef LAB18_PROJECT_H
#define LAB18_PROJECT_H
/**
 * @file functionsInitializations.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Kulish.P
 * @date 13-March-2021
 * @version 1.0
 */
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct basic_type {
    char ortopedic[4]; // наявність ортопедичності
    char model[12]; // назва моделі
    int price; // ціна
    struct insole {
        int size_insole;  // розмір стільки
        int length_insole; // довижна стільки
    }insole;
    char brand[8];  // назва бренду
};
void ShowData(struct basic_type* sneakers, const int N);
void GetData(struct basic_type* sneakers,const int N);

char* insert(char *main_str_ptr,char *insert_str_ptr,int insert_index);

char* reduce(char *main_str_ptr,int start_index_of_reducing,int end_index_of_reducing);
void add_struct(struct basic_type * sneakers,const int N);
void delete_struct(struct basic_type *sneakers,const int N,int number_Of_Struct_To_Delete);
#endif
