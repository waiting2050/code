#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int number = rand()%100 + 1;
	int count = 0;
	int a =0;
	printf("���Ѿ��뵽��һ��1~100����\n");
	system("pause");
	
	do{
		printf("��������\n");
		count++;
		scanf("%d", &a);
		if( a > number ){
			printf("�������������");
		}else if( a < number ){
			printf("���������С��");
		}
		
	}while( a != number );
	printf("nb!��ֻ����%d�ξͲ¶�������\n", count);
	
	return 0;
}
