#include <stdio.h>
#include <string.h>

//输出所有姓名
void showName(char *a[],int size);

//对多个字符串利用地址交换进行排序
void sort(char *a[],int size);

int main() {
  char *name[]={"赖澜涛" ,"陈少峰","魏杰","高潮","蓝求财","张秋玲","陈健"};
  int size=sizeof(name)/sizeof(name[0]); 
  
  puts("排序前姓名如下：");
  showName(name,size);
  
  sort(name,size);
  puts("\n排序后姓名如下：");
  showName(name,size);
}

//对多个字符串利用地址交换进行排序
void sort(char *s[],int size) {
  for (int i=0;i<size-1;i++) 
    for (int j=0;j<size-i-1;j++) 
      if (strcmp(s[j],s[j+1])>0) {
        char *tmp=s[j];s[j]=s[j+1];s[j+1]=tmp;
      }
}

//输出所有姓名
void showName(char *a[],int size) {
  for (int i=0;i<size;i++)
    printf("%s\n",a[i]);
} 