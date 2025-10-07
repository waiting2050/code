#include<stdio.h>

int main()
{
	int x;
	printf("请输入一个正整数\n");
	scanf("%d", &x);
	int u;
	int t = 0;
	
	while(x > 0){	
	u = x%10;
	x /= 10;
	t = 10*t + u; 
}
	printf("%d", t);
	
	return 0;
 } 
