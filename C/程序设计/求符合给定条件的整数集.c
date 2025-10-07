#include<stdio.h>

int main()
{
	int i, j, k;
	int cnt = 0;
	int A;
	scanf("%d", &A);
	
	for( k=A; k<=A+3; k++ ){
		for( j=A; j<=A+3; j++ ){
			for( i=A; i<=A+3; i++ ){
				if( i!=j && i!=k && k!=j){
					printf("%d%d%d", k, j, i);
					cnt ++;
					if( cnt%6 == 0){
						printf("\n");
					}
					else{
						printf(" ");
					}
				}
			}
		}
	}
	
	return 0;
}
