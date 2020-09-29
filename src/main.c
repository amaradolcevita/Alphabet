#include "func.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int i, j;
    long count = 0, max = 0;
    FILE *op, *sort;
    char name_1[1000], name_2[1000], request[1002], symbol, pred = '.';
    char** slovaDyn;
    printf("Enter the file name: ");
    scanf("%s", request);
    strcpy(name_1, "../texts/");
    strcpy(name_2, "../Sort/");
    strcat(name_1, request);
    strcat(name_2, request);
    sort = fopen(name_2, "w");
    op = fopen(name_1, "r");
    if (op == NULL) {
        printf("Wrong File!");
        system("PAUSE");
        return 0;
    }
    WordCount(&max, &count, name_1);
    char** slovaDyn;
    slovaDyn = (char**)malloc(count * sizeof(char*));
    for (i = 0; i < count; i++) {
        slovaDyn[i] = (char*)malloc(max * sizeof(char));
    }
    WordsArray(slovaDyn, name_1, count, max);
    Sort(slovaDyn, count, max);
return 0;
}
