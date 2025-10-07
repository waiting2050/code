#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i = 1;
	double sum = 0.0;
	int mark = 1;
	
	for( ; i <= n; i++ ){
		sum += mark*1.0/i;
		mark = -mark;
	}
	printf("f(%d)=%f", n, sum);
	
	return 0;
}
