//数组中元素的折半交换
#include <stdio.h>

//输出数组元素
void showArray(int a[],int size);

int main() {
  int a[]={1,2,3,4,5,6,7,8,9};
  int size=sizeof(a)/sizeof(a[0]);
  
  puts("原始数组：");
  showArray(a,size);
  
  for (int i=0;i<=(size-1)/2;i++) {
    int j=size-1-i;
    int t=a[j];a[j]=a[i];a[i]=t;
  }
  
  puts("交换后数组：");
  showArray(a,size);
}

//输出数组元素
void showArray(int a[],int size) {
  for (int i=0;i<size;i++)
    printf("%d ",a[i]);
  putchar('\n');
}