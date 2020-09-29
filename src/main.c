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
    char name_1[1000], name_2[1000], zapros[1002], symbol, pred = '.';
    char** slovaDyn;
    printf("Enter the file name: ");
    scanf("%s", zapros);
    strcpy(name_1, "../texts/");
    strcpy(name_2, "../Sort/");
    strcat(name_1, zapros);
    strcat(name_2, zapros);
    sort = fopen(name_2, "w");
    op = fopen(name_1, "r");
    if (op == NULL) {
        printf("Wrong File!");
        system("PAUSE");
        return 0;
    }	
return 0;
}
