//ʵ��������֤
#include <stdio.h>
#include <conio.h>        //getch������Ҫ
#include <string.h>       //strcmp������Ҫ

#define KEY_LEN 6         //���볤��
#define TIMES 3           //�������Ե�������

void get_input(char *s);  //����û����������(������ڲ���s��)

int main() {
  char key[]="123456";    //����
  char s[KEY_LEN+1];      //����û����������
  unsigned int count=0;   //������ԵĴ���
  do {
    get_input(s);
  } while (strcmp(s,key)&&++count<TIMES);
  if (!strcmp(s,key)) 
    printf("�������������ȷ��\n");
  else
    printf("�����������ѳ�������Ĵ�����\n");
}

//����û����������(������ڲ���s��)
void get_input(char *s) {
  printf("���������룺");
  for (int i=0;i<KEY_LEN;i++) {
    s[i]=getch();
    putchar('*');   //��*��������������ַ�
  }
  s[KEY_LEN]='\0';
  putchar('\n');
}
