#define _CRT_SECURE_NO_WARNINGS 
#include "array.h"
#include <stdlib.h>
#include <stdio.h>

//Array array_creat(int init_size);创造数组
//void array_free(Array* a);释放内存
//int array_size(const Array* a);
//int* array_at(Array* a, int index);
//void array_inflate(Array* a, int more_size);

Array array_creat(int init_size) {
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int) * a.size);
	return a;
}
void array_free(Array* a) {
	free(a->array);
	a->array = NULL;
	a->size = 0;
}
int array_size(const Array* a) {
	//封装
	return a->size;
}
int* array_at(Array* a, int index) {
	return &(a->array[index]);
}
int main(int argc, char* argv[])
{
	Array a = array_creat(100);
	printf("%d\n", array_size(&a));
	*array_at(&a, 0) = 10;
	printf("%d\n", *array_at(&a, 0));
	array_free(&a);

	return 0;
}


