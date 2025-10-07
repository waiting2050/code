#include<stdio.h>

int main()
{
	int x;
	int cnt[10];				//定义数组 
	int i=0;
	
	for(; i<10; i++){			//初始化数组 
		cnt[i]=0;
	}
	scanf("%d", &x);
	while(x!=-1){				//数组参与运算 
		if(x>=0 && x<=9){
			cnt[x]++;
		}
		scanf("%d", &x);
	}
	for(i=0; i<10; i++){		//遍历数组输出 
		printf("%d:%d\n", i, cnt[i]);
	}
	
	return 0;
}
