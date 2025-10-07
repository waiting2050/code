//实现密码验证
#include <stdio.h>
#include <conio.h>        //getch函数需要
#include <string.h>       //strcmp函数需要

#define KEY_LEN 6         //密码长度
#define TIMES 3           //允许重试的最大次数

void get_input(char *s);  //获得用户输入的密码(存至入口参数s中)

int main() {
  char key[]="123456";    //密码
  char s[KEY_LEN+1];      //存放用户输入的密码
  unsigned int count=0;   //存放重试的次数
  do {
    get_input(s);
  } while (strcmp(s,key)&&++count<TIMES);
  if (!strcmp(s,key)) 
    printf("你输入的密码正确！\n");
  else
    printf("你输入密码已超过允许的次数！\n");
}

//获得用户输入的密码(存至入口参数s中)
void get_input(char *s) {
  printf("请输入密码：");
  for (int i=0;i<KEY_LEN;i++) {
    s[i]=getch();
    putchar('*');   //用*代替输入的密码字符
  }
  s[KEY_LEN]='\0';
  putchar('\n');
}
