#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int number = rand()%100 + 1;
	int count = 0;
	int a =0;
	printf("我已经想到了一个1~100的数\n");
	system("pause");
	
	do{
		printf("请猜这个数\n");
		count++;
		scanf("%d", &a);
		if( a > number ){
			printf("你输入的数大了");
		}else if( a < number ){
			printf("你输入的数小了");
		}
		
	}while( a != number );
	printf("nb!你只用了%d次就猜对了数字\n", count);
	
	return 0;
}
