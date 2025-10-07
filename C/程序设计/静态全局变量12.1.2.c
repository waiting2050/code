#include<stdio.h>

int f(void);

int gall=12;

int main(){
	f();
	f();
	f();
	
	return 0;
}

int f(void){
	static int all=1;
	printf("in %s all=%d\n", __func__, all);
	all+=2;
	printf("agn in %s all=%d\n", __func__, all);
	return all;
}
