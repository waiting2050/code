#include<stdio.h>

int main()
{
	int a;
	int n = 0;
	int sum = 0;
	printf("�����뼸��������������\"-1\"Ϊ��������\n");
	scanf("%d", &a);
	
	while( a != -1 ){
		n ++;
		sum += a;
		scanf("%d", &a);
	}
	printf("ƽ����Ϊ%f", 1.0*sum/n);
	
	return 0;
}


