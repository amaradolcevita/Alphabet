#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WordCount(long* max, long* count, char* filename);

void WordsArray(char** slovaDyn, char* filename, long count, long max);

void Sort(char** A, int size, int M);
