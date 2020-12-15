/**
* @mainpage
* # Загальне завдання
* 1. **Розробити** 
*	Програму яка знаходить безперервну послідовність позитивних чисел з максимальною сумою,та переписує таку послідовність у 	*	результуючий масив
*
* # Опис програми
* 2. **Функціональне призначення**
*	Програма призначена для знахождення безперервної послідовності позитивних чисел з максимальною сумою.
* 3. **Опис логічної структури**
*	Програма складається з функції заповненя масиву.
*	Після заповнення масиву виконується цикл довжиною заповненого масиву
*	У цьому циклі,якщо число позитивне - заходим у перевірку
*	зайшовши у перевірку відразу до поточної суми додаємо поточний елемент
*	1 перевірка - якщо це перший елемент або І-1 елемент меньше 1 запам'ятовується поточний початковий індекс
*	2 перевірка - якщо це кінцевий елемент або і+1 елемент меньше 1 - запам'ятовується поточний кінцевий індекс проміжку
*	3 перевірка - якщо поточна сума більша за (початкову"кінцеву" = 0) , запам'ятовується як "кінцева сума = поточній" 
* @author Kulish Pavlo.
* @date 15-Dec-2020
*/

/**
* @file main.c
* Програма призначена для заповнення масиву заданою кількістю простих чисел.
* @author Kulish Pavlo
* @version 0.4 
* date 15.12.2020 
*
*/
#include <malloc.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    /*Об'явлення функції заповнення масиву*/
    int fucntionFillingMainArray(const int length, int* mainarray);
    /*@lengthMainArray Змінна довжини масиву*/
    const int lengthMainArray = 20;
    /*Об'явлення головного масиву @mainArray та виділення під нього потрібної кількості пам'яті*/
    int* mainArray = (int*)malloc(lengthMainArray * sizeof(int));
    /*Звернення до функції заповнення масиву @mainArray */
    *mainArray = fucntionFillingMainArray(lengthMainArray, mainArray);
    /*@finalSum Змінна для фіксування остаточної сумми*/
    int finalSum = -1;
    /*@finalBeginSegmentIndex Змінна для фіксування початкового індексу проміжку*/
    int finalBeginSegmentIndex = -1;
    /*@finalEndSegmentIndex Змінна для фіксування кінцевого індексу проміжку*/
    int finalEndSegmentIndex = -1;
    /*@actualSumm Змінна для тимчасової(не остаточної) сумми */
    int actualSumm = 0;
    /*@actualBeginSegmentIndex Змінна для тимчасового початкового індексу проміжку*/
    int actualBeginSegmentIndex = -1;
    /*@actualEndSegmentIndex Змінна для поточного кінцевого індексу проміжку*/
    int actualEndSegmentIndex = -1;
    
    
    
    for (int i = 0; i < lengthMainArray; i++) {
        if (mainArray[i] > 0) {
            actualSumm += mainArray[i];
            if (i == 0 || mainArray[i - 1] < 1) {
                actualBeginSegmentIndex = i;
            }
            if (i == lengthMainArray - 1 || mainArray[i + 1] < 1) {
                actualEndSegmentIndex = i;
                if (actualSumm > finalSum) {
                    finalSum = actualSumm;
                    finalBeginSegmentIndex = actualBeginSegmentIndex;
                    finalEndSegmentIndex = actualEndSegmentIndex;
                }
                actualSumm = 0;
            }
        }
    }
    
    
    
    printf("\n%s%d\n", "sum = ", finalSum);
    printf("\n%s%d\n", "begin index = ", finalBeginSegmentIndex);
    printf("\n%s%d\n", "end index = ", finalEndSegmentIndex);
    /*@resLength Змінна - розмір результуючого масиву в залежності від потрібної кількості*/
    const int resLength = finalEndSegmentIndex - finalBeginSegmentIndex + 1;
    /*Об'явлення масиву @resultArray та виділення пам'яті під результуючий масив відштовхуючись від потрібної кількості*/
    int* resultArray = (int*)malloc(resLength * sizeof(int));
    /*Вказівка @original на адрес масиву @mainArray з остаточним індексом @finalBeginSegmentIndex*/
    int* original = &mainArray[finalBeginSegmentIndex];
    /*Цикл заповнення результуючого масиву*/
    for (int i = 0; i < resLength; i++) {
        *resultArray = *original;
        resultArray++;
        original++;
    }
    resultArray = resultArray - resLength;

    /*Цикл виведення результуючого масиву*/
    for (int i = 0; i < resLength; i++) {
        printf("\n%s%d%s%d", "result[", i, "]= ", resultArray[i]);
    }
}

int fucntionFillingMainArray(const int length,int *mainarray) {
    for (int i = 0; i < length; i++) {
        *mainarray++ = rand() % 200 + -10;
    }
    return 0;
}
