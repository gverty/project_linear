#include <malloc.h>
#include <time.h>
int main()
{
    srand(time(NULL));

    float arrayFiller(const int lengthToFill, float massivForFunction[]);

    const int mainLengthArray = 20;
    float* mainArray = (float*)malloc(mainLengthArray * sizeof(float));

    *mainArray = arrayFiller(mainLengthArray, mainArray);

    int finalBeginSegmentIndex = -1;
    int finalEndSegmentIndex = -1;
    int finalLengthValue = -1;
    int actualLengthSegment;

    int actualBeginIndexFromMainArray = -1;
    int actualEndIndexFromMainArray = -1;
    int found = 0;

    for (int i = 0; i < mainLengthArray; i++) {


        if (found == 0 && i < mainLengthArray - 1 && (mainArray[i] < mainArray[i + 1]))
        {
            actualBeginIndexFromMainArray = i;
            found = 1;
        }
        if (found == 1 && (i == mainLengthArray - 1 || mainArray[i] > mainArray[i + 1]))
        {
            actualEndIndexFromMainArray = i;
            found = 0;
        }
        actualLengthSegment = actualEndIndexFromMainArray - actualBeginIndexFromMainArray;
        if (actualLengthSegment > finalLengthValue)
        {
            finalLengthValue = actualLengthSegment;
            finalBeginSegmentIndex = actualBeginIndexFromMainArray;
            finalEndSegmentIndex = actualEndIndexFromMainArray;
        }
    }
    printf("%s%d\n", "begin index = ", finalBeginSegmentIndex);
    printf("%s%d\n", "end index = ", finalEndSegmentIndex);
    if (finalBeginSegmentIndex > 0) {
        const int lengthResultArray = finalEndSegmentIndex - finalBeginSegmentIndex + 1;
        float* resultArray = (float*)malloc(lengthResultArray * sizeof(float));
        //указатель на адрес главного массива 
        float* original = &mainArray[finalBeginSegmentIndex];

        for (int i = 0; i < lengthResultArray; i++) {
            *resultArray = *original;
            resultArray++;
            original++;
        }
        resultArray = resultArray - lengthResultArray;

        for (int i = 0; i < lengthResultArray; i++) {
            printf("\n%s%d%s%f\n", "result[", i, "]= ", resultArray[i]);
        }
    }
    else {
        printf("%s\n", "Havent sequence");
    }
}

float arrayFiller(const int lengthToFill,float massivForFunction[]) {
    float* functionMassivePointer = massivForFunction;
    for (int i = 0; i < lengthToFill; i++) {
        *functionMassivePointer++ = (rand() % 50 + -1) / 1.3;
    }
    return 0;
}

