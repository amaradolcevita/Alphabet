#include "func.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void WordCount(long* max, long* count, char* filename) {
	char symbol, pred = '.';
	long len = 1;
	long counts = 0;
	FILE* op = fopen(filename, "r");
	symbol = getc(op);
	while ((symbol = getc(op)) != EOF) {
		if ((symbol > 64 && symbol < 91) || (symbol > 96 && symbol < 123) ||
			(symbol > 191 && symbol < 256)) {
			if ((pred > 64 && pred < 91) || (pred > 96 && pred < 123) ||
				(pred > 191 && pred < 256)) {
				len++;

			}
			else {
				if (len > * max)
					*max = len;
				len = 1;
				counts++;

			}

		}
		pred = symbol;

	}
	*max++;
	*count = counts;
	fclose(op);
}

void WordsArray(
	char** slovaDyn, char* filename, long count, long max)
{
	char slova[count][max], symbol, pred;
	int i = -1, j = 0;
	FILE* op = fopen(filename, "r");
	rewind(op);
	pred = '.';
	while ((symbol = getc(op)) != EOF) {
		if ((symbol > 64 && symbol < 91) || (symbol > 96 && symbol < 123)) {
			if (!((pred > 64 && pred < 91) || (pred > 96 && pred < 123))) {
				i++;
				j = 1;
				if (symbol > 64 && symbol < 91)
					symbol += 32;
				slovaDyn[i][0] = symbol;
			}
			else {
				if (symbol > 64 && symbol < 91)
					symbol += 32;
				slovaDyn[i][j] = symbol;
				j++;
				slovaDyn[i][j] = 0;
			}
		}
		pred = symbol;
	}
	fclose(op);
}

void Sort(char** A, int size, int M)
{
	char temp[M];
	for (int n = 1; n < size; n++)
		for (int m = 0; m < size - n; m++) {
			int code = strcmp(A[m + 1], A[m]);
			if (code < 0) {
				strcpy(temp, A[m]);
				strcpy(A[m], A[m + 1]);
				strcpy(A[m + 1], temp);
			}
		}
}

int Unique(char** S, int s)
{
	for (int i = 0; i < s; i++) {
		for (int j = i + 1; j < s; j++) {
			if (strcmp(S[i], S[j]) == 0 && S[j] != NULL) {
				for (int shift = j; shift < s - 1; shift++) {
					strcpy(S[shift], S[shift + 1]);
				}
				s--;
				if (strcmp(S[i], S[j]) == 0 && S[j] != NULL) {
					j--;
				}
			}
		}
	}
	return s;
}
