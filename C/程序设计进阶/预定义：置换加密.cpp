//�û�����
#include <stdio.h>
#include <ctype.h>

//��Կ
#define KEY 3

void encryption(char *s) {
  while (*s) {
    if (islower(*s)) *s=(*s-'a'+KEY)%26+'a';
    if (isupper(*s)) *s=(*s-'A'+KEY)%26+'A';
    if (isdigit(*s)) *s=(*s-'0'+KEY)%10+'0';
    s++;
  }
}

void decryption(char *s) {
  while (*s) {
    if (islower(*s)) *s=(*s-'a'+(26-KEY))%26+'a';
    if (isupper(*s)) *s=(*s-'A'+(26-KEY))%26+'A';
    if (isdigit(*s)) *s=(*s-'0'+(10-KEY))%10+'0';
    s++;
  }
}

int main() {
  char str[]= "Ԥ���壺�û������ı�.txt";
  
  puts("ԭʼ�ַ�����");
  puts(str);
  
  encryption(str);
  puts("�û����ܺ���ַ�����");
  puts(str);
  
  decryption(str);
  puts("���ܺ���ַ�����");
  puts(str);
}
