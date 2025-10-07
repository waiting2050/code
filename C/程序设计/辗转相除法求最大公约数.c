#include<stdio.h>

int main()
{
	//辗转相除法: 
	//如果b等于0，计算结束，a为最大公约数; 
	//否则，计算a除以b的余数，让a等于b，而b等于那个余数;
	//回到第一步 
	
	int a, b;
	scanf("%d %d", &a, &b);
	int t;
	
	while( b != 0){
		t = a%b;
		a = b;
		b = t;
	}
	printf("gcd=%d\n", a);
	
	return 0;
}
