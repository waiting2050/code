//演示结构数组的使用（非常简单的学籍系统）
#include <stdio.h>

#define N 6          //学生数
#define NAME_SIZE 14 //姓名最长7个汉字

enum SexType {male,female}; //性别

struct Student {            //学生结构(类型)
  int   num;                //学号(实用系统应定义成字符型)
  char  name[NAME_SIZE+1];  //姓名
  enum  SexType sex;        //性别
  short age;                //年龄(实用系统应定义成出生日期)
  float score;              //成绩(实用系统一般不会这么做)
}; 

/*输入学生信息(不完善的程序)*/
void input(Student st[]);
/*按成绩从高到低排序*/
void sort(Student st[]);
/*输出学生信息*/
void print(Student st[]);

//充分体现“分而治之”的思想！
int main() {
  struct Student students[N];
  /*输入学生信息*/
  input(students);
  /*按成绩从高到低排序*/
  sort(students);
  /*输出学生信息*/
  print(students);
}

/*输入学生信息(不完善的程序)*/
void input(Student st[]) {
  char c; //存放性别字符(f或m)
  printf("请输入学号,姓名,性别(f或m),年龄,成绩：\n");
  for (int i=0;i<N;i++) {
    scanf("%d %s %c %d %f",&st[i].num,st[i].name,&c,&st[i].age,&st[i].score);
    st[i].sex=((c=='m')?male:female);
  }
}

/*按成绩从高到低排序，另一种形式的冒泡排序！*/
void sort(Student st[]) {
  struct Student temp;
  for (int i=0;i<N-1;i++)
    for (int j=i+1;j<N;j++)
      if (st[i].score<st[j].score) {
        temp=st[i]; //结构可以直接赋值
        st[i]=st[j];
        st[j]=temp;
      }
}

/*输出学生信息*/
void print(Student st[]) {
  printf("%8s%16s%8s%8s%8s\n",
    "学号","姓名","性别","年龄","成绩");
  for (int i=0;i<N;i++) {
    printf("%8d%16s",st[i].num,st[i].name);
    if (st[i].sex==male) printf("%8s","男");
    else printf("%8s","女");
    printf("%8hd%8.1f\n",st[i].age,st[i].score);
  }
}

/*
输入数据(学号,姓名,性别(f或m),年龄,成绩)：
1001 张三 f 20 86
1002 李四 m 19 77
1003 王五 m 21 95
1004 张三风 f 20 87
1005 李四强 m 18 68
1006 王五一 m 22 91
*/
