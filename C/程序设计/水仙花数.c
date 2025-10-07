#include<stdio.h>

int main()
{
	int n;
	printf("请输入位数,位数在3~7间:\n");
	scanf("%d", &n);
	int ret = 1;
	int t = 1;
	
	for( ; ret<n; ret++){
		t *= 10;
	}                       //取得下界 t,ret为计数器 
	int i = t;
	for( ; i<t*10; i++){  /*遍历100~999*/ 
		int j = i;
		int k;
		int sum=0;
		do{                 /*分离整数*/ 
			int k = j%10;
			j /= 10;
			int p = k;
			int cnt = 1;
			for(; cnt<n; cnt++){  /*幂*/ 
				p *= k;
			}
			sum += p;
			
		}while( j>0 );
		if( sum==i ){
			printf("%d\n", i);
		}
	}
	return 0;
}
