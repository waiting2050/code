#include<stdio.h>

int main()
{
	int x;
	int cnt[10];				//�������� 
	int i=0;
	
	for(; i<10; i++){			//��ʼ������ 
		cnt[i]=0;
	}
	scanf("%d", &x);
	while(x!=-1){				//����������� 
		if(x>=0 && x<=9){
			cnt[x]++;
		}
		scanf("%d", &x);
	}
	for(i=0; i<10; i++){		//����������� 
		printf("%d:%d\n", i, cnt[i]);
	}
	
	return 0;
}
