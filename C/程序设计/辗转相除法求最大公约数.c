#include<stdio.h>

int main()
{
	//շת�����: 
	//���b����0�����������aΪ���Լ��; 
	//���򣬼���a����b����������a����b����b�����Ǹ�����;
	//�ص���һ�� 
	
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
