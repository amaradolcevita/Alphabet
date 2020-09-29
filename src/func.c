#include "func.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void WordCount(long * max, long * count, char* filename)
{
    char symbol, pred = '.';
    long dlin = 1;
    long counts = 0;
    FILE* op = fopen(filename, "r");
    symbol = getc(op);
    while ((symbol = getc(op)) != EOF) {
        if ((symbol > 64 && symbol < 91) || (symbol > 96 && symbol < 123)
            || (symbol > 191 && symbol < 256)) {
            if ((pred > 64 && pred < 91) || (pred > 96 && pred < 123)
                || (pred > 191 && pred < 256)) {
                dlin++;
            } else {
                if (dlin > *max)
                    *max = dlin;
                dlin = 1;
                counts++;
            }
        }
        pred = symbol;
    }
    *max++;
    *count = counts;
    fclose(op);
}
