#include<stdio.h>

int main()
{
	// 找零 
	int one, two, five;
	printf("请输入金额(元:)\n");
	int money;
	scanf("%d", &money);
	
	for( five = 1; five < money*10/5; five++){
		for( one = 1; one < money*10; one++){
			for( two = 1; two < money*10/2; two++ ){
				if( five*5 + two*2 + one == money*10 ){
					printf("找您%d个五角，%d个两角,%d个一角\n", five, two, one);
					goto out;
				}
			}
		}
	}
	out:
	return 0;
}
