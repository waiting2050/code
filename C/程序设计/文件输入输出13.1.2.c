#include<stdio.h>

int main(){
	FILE *fp = fopen("12.in", "w");
	if(fp){
		int num=100;
		fscanf(fp, "%d", &num);
		printf("%d\n", num);

	}else{
		printf("�޷����ļ�\n");
	}
	return 0;
}
