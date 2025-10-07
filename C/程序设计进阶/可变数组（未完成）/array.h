#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>

typedef struct {
	int* array;
	int size;
}Array;

Array array_creat(int init_size);
void array_free(Array* a);
int array_size(const Array* a);
int* array_at(Array* a, int index);
void array_inflate(Array* a, int more_size);

#endif
