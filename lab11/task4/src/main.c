#include <malloc.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    /*Об'явлення функції сортування*/
    int BubbleSorting(int lengthResultingArray, int* ResultingArray);
    /*Об'явлення функції заповнення масиву*/
    int fillingMainArray(int lengthMainArray, int** mainArray);
    /* Псевдовипадкове задання розмірность матриці */
    int lengthMainArray = rand() % 7 + 5;

    /* Виділення пам'яті під кількість елементів масиву */
    int* resultArray = (int*)malloc(lengthMainArray * sizeof(int));

    /* Задання динамічного двовимірного масиву */
    int** Mass = (int**)malloc(lengthMainArray * sizeof(int*));
    for (int i = 0; i < lengthMainArray; i++) {
        *(Mass + i) = (int*)malloc(lengthMainArray * sizeof(int));
    }

    /*Масив заповнюється псевдовипадковими числами,звертаючись до функції*/
    **Mass = fillingMainArray(lengthMainArray,Mass);

    /* Цикл для перенесення діагональних елементів в массив для результату */
    printf("\n%s\n", "Not sorted array: ");
    for (int i = 0; i < lengthMainArray; i++) {
        *(resultArray + i) = *(*(Mass + i) + i);
        printf("%4d", *(resultArray + i));
    }
   
    /*  Звернення до функції сортування */
    *resultArray = BubbleSorting(lengthMainArray,resultArray);
    
    /* Цикл для виведення сортированих елементів результуючого масиву */
    printf("\n%s\n", "Sorted array: ");
    for (int i = 0; i < lengthMainArray; i++) {
        printf("%4d", *(resultArray + i));
    }
    return 0;
}

int BubbleSorting(int lengthResultingArray,int *ResultingArray) {
    int temp;
    for (int i = 0; i < lengthResultingArray - 1; i++) {
        for (int j = 0; j < lengthResultingArray - i - 1; j++) {
            if (*(ResultingArray + j) > *(ResultingArray + j + 1)) {
                temp = *(ResultingArray + j);
                *(ResultingArray + j) = *(ResultingArray + j + 1);
                *(ResultingArray + j + 1) = temp;
            }
        }
    }
    return 0;
}

int fillingMainArray(int lengthMainArray, int** mainArray) {
    for (int i = 0; i < lengthMainArray; i++) {
        for (int j = 0; j < lengthMainArray; j++) {
            *(*(mainArray + i) + j) = rand() % 10 + 0;
            printf("%4d", *(*(mainArray + i) + j));
        }
        printf("\n");
    }
    return 0;
}
