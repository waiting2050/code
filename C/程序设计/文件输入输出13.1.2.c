#include<stdio.h>

int main(){
	FILE *fp = fopen("12.in", "w");
	if(fp){
		int num=100;
		fscanf(fp, "%d", &num);
		printf("%d\n", num);

	}else{
		printf("无法打开文件\n");
	}
	return 0;
}
