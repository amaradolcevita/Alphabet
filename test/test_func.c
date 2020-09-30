#include "../src/func.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, Sort)
{
	int i;
	char** arr;
	arr = (char**)malloc(5 * sizeof(char*));
	for (i = 0; i < 5; i++) {
		arr[i] = (char*)malloc(10 * sizeof(char));
	}

	strcpy(arr[0], "storm");
	strcpy(arr[1], "crash");
	strcpy(arr[2], "our");
	strcpy(arr[3], "lands");
	strcpy(arr[4], "our");

	Sort(arr, 5, 10);

	char** arrTeor;
	arrTeor = (char**)malloc(5 * sizeof(char*));
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

CTEST(arithmetic_suite, WordCount)
{
	char name[1000];
	strcpy(name, "../test/test.txt");
	long max = 0, count = 0;
	WordCount(&max, &count, name);
	const long countTeor = 4, maxTeor = 5;
	ASSERT_EQUAL(maxTeor, max);
	ASSERT_EQUAL(countTeor, count);
}
CTEST(arithmetic_suite, Unique)
{
	long s = 3, sTeor = 2;
	int i;
	char** arr;
	arr = (char**)malloc(5 * sizeof(char*));
	for (i = 0; i < 5; i++) {
		arr[i] = (char*)malloc(10 * sizeof(char));
	}
	strcpy(arr[0], "our");
	strcpy(arr[1], "our");
	strcpy(arr[2], "storm");

	char** arrTeor;
	arrTeor = (char**)malloc(5 * sizeof(char*));
	for (i = 0; i < 5; i++) {
		arrTeor[i] = (char*)malloc(10 * sizeof(char));
	}

	strcpy(arrTeor[0], "our");
	strcpy(arrTeor[1], "storm");
	s = Unique(arr, s);
	ASSERT_EQUAL(sTeor, s);
	ASSERT_STR(arrTeor[0], arr[0]);
	ASSERT_STR(arrTeor[1], arr[1]);
}
CTEST(arithmetic_suite, WordsArray)
{
	int i;
	char name[1000];
	strcpy(name, "../test/test.txt");
	long count = 4, max = 5;
	char** slovaDyn;
	slovaDyn = (char**)malloc(count * sizeof(char*));
	for (i = 0; i < 4; i++) {
		slovaDyn[i] = (char*)malloc(max * sizeof(char));
	}
	char** arr;
	arr = (char**)malloc(count * sizeof(char*));
	for (i = 0; i < 4; i++) {
		arr[i] = (char*)malloc(max * sizeof(char));
	}
	strcpy(arr[0], "crash");
	strcpy(arr[1], "our");
	strcpy(arr[2], "lands");
	strcpy(arr[3], "storm");
	WordsArray(slovaDyn, name, count, max);
	ASSERT_STR(arr[0], slovaDyn[0]);
	ASSERT_STR(arr[1], slovaDyn[1]);
	ASSERT_STR(arr[2], slovaDyn[2]);
	ASSERT_STR(arr[3], slovaDyn[3]);
}
