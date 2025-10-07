#include<stdio.h>

int f(void);

int gall=12;

int main(){
	printf("in %s gall=%d\n", __func__, gall);
	f();
	printf("agn in %s gall=%d\n", __func__, gall);
	
	return 0;
}

int f(void){
	printf("in %s gall=%d\n", __func__, gall);
	gall+=2;
	printf("agn in %s gall=%d\n", __func__, gall);
	return gall;
}
