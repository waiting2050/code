#include<stdio.h>

int main()
{
	// ���� 
	int one, two, five;
	printf("��������(Ԫ:)\n");
	int money;
	scanf("%d", &money);
	
	for( five = 1; five < money*10/5; five++){
		for( one = 1; one < money*10; one++){
			for( two = 1; two < money*10/2; two++ ){
				if( five*5 + two*2 + one == money*10 ){
					printf("����%d����ǣ�%d������,%d��һ��\n", five, two, one);
					goto out;
				}
			}
		}
	}
	out:
	return 0;
}
