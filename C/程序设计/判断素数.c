#include <stdio.h>
 
int main()
{
	// 判断素数
	
	int x;
	scanf("%d", &x);
	int i = 2;
	int f = 1;
	
	for( i=2; i < x; i++){
		if( x%i == 0){
		    f = 0;
			break;
		}
	}  
	if( f == 1 && x != 1){
		printf("是素数"); 
	}else{
		printf("不是素数");
	}
	return 0;
} 
