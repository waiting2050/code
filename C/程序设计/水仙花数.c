#include<stdio.h>

int main()
{
	int n;
	printf("������λ��,λ����3~7��:\n");
	scanf("%d", &n);
	int ret = 1;
	int t = 1;
	
	for( ; ret<n; ret++){
		t *= 10;
	}                       //ȡ���½� t,retΪ������ 
	int i = t;
	for( ; i<t*10; i++){  /*����100~999*/ 
		int j = i;
		int k;
		int sum=0;
		do{                 /*��������*/ 
			int k = j%10;
			j /= 10;
			int p = k;
			int cnt = 1;
			for(; cnt<n; cnt++){  /*��*/ 
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
