#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int Unique(char** S, int s);

void WordCount(long* max, long* count, char* filename);

void WordsArray(char** slovaDyn, char* filename, long count, long max);

void Sort(char** A, int size, int M);

#endif
