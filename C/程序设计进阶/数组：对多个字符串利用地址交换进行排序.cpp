#include <stdio.h>
#include <string.h>

//�����������
void showName(char *a[],int size);

//�Զ���ַ������õ�ַ������������
void sort(char *a[],int size);

int main() {
  char *name[]={"������" ,"���ٷ�","κ��","�߳�","�����","������","�½�"};
  int size=sizeof(name)/sizeof(name[0]); 
  
  puts("����ǰ�������£�");
  showName(name,size);
  
  sort(name,size);
  puts("\n������������£�");
  showName(name,size);
}

//�Զ���ַ������õ�ַ������������
void sort(char *s[],int size) {
  for (int i=0;i<size-1;i++) 
    for (int j=0;j<size-i-1;j++) 
      if (strcmp(s[j],s[j+1])>0) {
        char *tmp=s[j];s[j]=s[j+1];s[j+1]=tmp;
      }
}

//�����������
void showName(char *a[],int size) {
  for (int i=0;i<size;i++)
    printf("%s\n",a[i]);
} 