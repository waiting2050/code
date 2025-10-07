//置换加密
#include <stdio.h>
#include <ctype.h>

//密钥
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
  char str[]= "预定义：置换加密文本.txt";
  
  puts("原始字符串：");
  puts(str);
  
  encryption(str);
  puts("置换加密后的字符串：");
  puts(str);
  
  decryption(str);
  puts("解密后的字符串：");
  puts(str);
}
