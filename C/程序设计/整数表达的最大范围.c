#include<stdio.h>

int main()
{	
	int a=0;
	int b=1;
	for(; ++a>0;);	
	printf("%d\n", a-1);
	while((a/=10)!=0){
		b++;
	}
	printf("%d", b);
	return 0;
}
