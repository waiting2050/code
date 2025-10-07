#include<stdio.h>

int main()
{
	int a;
	int n = 0;
	int sum = 0;
	printf("请输入几个正整数，输入\"-1\"为结束程序\n");
	scanf("%d", &a);
	
	while( a != -1 ){
		n ++;
		sum += a;
		scanf("%d", &a);
	}
	printf("平均数为%f", 1.0*sum/n);
	
	return 0;
}


