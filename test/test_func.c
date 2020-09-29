#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, Sort)  
{
    int i;
    char* arr;
    arr = (char*)malloc(5 * sizeof(char*));
    for (i = 0; i < 5; i++) {
        arr[i] = (char*)malloc(10 * sizeof(char));
    }

    strcpy(arr[0], "storm");
    strcpy(arr[1], "crash");
    strcpy(arr[2], "our");
    strcpy(arr[3], "lands");
    strcpy(arr[4], "our");

    Sort(arr, 5, 10);

    char* arrTeor;
    arrTeor = (char*)malloc(5 * sizeof(char*));
    for (i = 0; i < 5; i++) {
        arrTeor[i] = (char*)malloc(10 * sizeof(char));
    }

    strcpy(arrTeor[0], "crash");
    strcpy(arrTeor[1], "lands");
    strcpy(arrTeor[2], "our");
    strcpy(arrTeor[3], "our");
    strcpy(arrTeor[4], "storm");
    
    ASSERT_STR(arrTeor[0], arr[0]);
    ASSERT_STR(arrTeor[1], arr[1]);
    ASSERT_STR(arrTeor[2], arr[2]);
    ASSERT_STR(arrTeor[3], arr[3]);
    ASSERT_STR(arrTeor[4], arr[4]);
}

