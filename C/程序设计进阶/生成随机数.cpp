#include<stdio.h>
#include<stdlib.h>

#define TIMES 1000

int main() {
  int cnt[11]={0};
  
  unsigned int seed;
  printf("请输入非负的种子值:");
  scanf("%d",&seed);
  srand(seed);
  
  for(int j=0;j<TIMES;j++)
    cnt[rand()%10+1]++;
  
  int j;
  for(j=1;j<=10;j++)
    printf("%d出现了%d次\n",j,cnt[j]);
  putchar('\n');
  
  return 0;
}
