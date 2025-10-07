//简单的学生学籍管理系统(仅处理单科成绩)
#include <stdio.h>
#include <math.h>

#define NUM 10     /*学生总人数*/

/*输入学生的学号和成绩*/
void input (int sno[],float score[]);
/*计算并输出平均成绩*/
float ave(float score[]);
/*统计各分数段的人数*/
void mark_sect(float score[],short g[5]);
/*获得最高分对应的下标*/
int get_max_index(float score[]);
/*查找指定学号的学生（顺序查找！）*/
void search(int sno[],float score[]);
/*学生学号按从小到大排序*/
void sort_sno(int sno[],float score[]);
/*输出学生成绩表，含学号，成绩*/
void print(int sno[],float score[]);
/*查找指定学号的学生（二分法查找！递归过程）*/
void biquery(int sno[],float score[],int no,int low,int high);
/*学生成绩按从高到低排序*/
void sort_score(int sno[],float score[]);

int main() {
  int   sno[NUM];   /*保存学生学号*/
  float score[NUM]; /*保存学生成绩*/
  
  /*输入学生的学号和成绩*/
  input(sno,score);
  
  float aver=ave(score);
  printf("\n平均成绩为: %5.1f\n",aver);
  
  short grade[5]; /*保存各分数段的人数*/
  mark_sect(score,grade);
  
  //输出各分数段的人数
  printf("\n五个分数段的人数分别为：\n");
  for(int i=0;i<5;i++) printf("%c:%d  ",'A'+i,grade[i]);
  printf("\n");printf("\n");  //输出形如 A:2  B:2  C:3  D:2  E:1
  
  /*输出学生成绩表，含学号，成绩，标准分*/
  printf("学生成绩表:\n");
  printf("%5s%8s%8s\n","学号","成绩","标准分");
  for (i=0;i<NUM;i++)
    printf("%5d%8.1f%8.1f\n",sno[i],score[i],score[i]-aver);
  
  //输出最高分的学生
  int index=get_max_index(score); //获得最高分对应的下标
  printf("\n学生[%d]的成绩：%5.1f为最高分！\n\n",sno[index],score[index]);
  
  //查找指定学号的学生
  search(sno,score);
  
  /*学生学号按从大到小排序*/
  sort_sno(sno,score);
  /*输出学生成绩表，含学号，成绩*/
  print(sno,score);
  
  //查找指定学号的学生
  printf("\n");
  int no;
  char cont;
  do {
    printf("输入待查询的学号： ");
    scanf("%d",&no);
    biquery(sno,score,no,0,NUM-1);
    printf("继续查找吗(y/n)?");
    getchar();
    cont=getchar();
  } while (cont=='y' || cont=='Y');
  
  /*学生成绩按从高到低排序*/
  sort_score(sno,score);
  
  /*输出学生成绩表及名次*/
  printf("\n学生成绩表:\n");
  printf("%5s %8s %4s\n","学号","成绩","名次");
  int j=0/*名次*/;
  float g=-1;
  for (i=0;i<NUM;i++) {
    if (g!=score[i]) {
      g=score[i];
      j=i+1;
    }
    printf("%5d %8.1f (%2d)\n",sno[i],score[i],j);
  }
} // END main

/*输入学生的学号和成绩*/
void input (int sno[],float score[]) {
  printf("输入%d个学生的学号和成绩:\n",NUM);
  for (int i=0;i<NUM;i++) 
    scanf("%d%f",&sno[i],&score[i]);
} //输入格式1001 70.5 1010 56 1003 88.5 1009 92 1002 64 1006 77 1008 63 1004 83.5 1007 70.5 1005 100

/*计算并输出平均成绩*/
float ave(float score[]) {
  float ave=0;
  for(int i=0;i<NUM;i++) ave+=score[i];
  ave/=NUM;
  return ave;
}

/*统计各分数段的人数*/
void mark_sect(float score[],short g[5]) {
  for(int i=0;i<5;i++) g[i]=0; //置初值
  for (i=0;i<NUM;i++)
    switch ((int)floor(score[i]/10) ) {
      case 10:g[0]++;break; /*100*/
      case  9:g[0]++;break; /*90--99*/
      case  8:g[1]++;break; /*80--89*/
      case  7:g[2]++;break; /*70--79*/
      case  6:g[3]++;break; /*60--69*/
      default:g[4]++;       /* 0--59*/
  }
}

/*获得最高分对应的下标*/
int get_max_index(float score[]) {
  float max=-1;
  short pos=-1;  /*初始化*/
  for (int i=0;i<NUM;i++) {
    if (score[i]>max) {
      max=score[i];
      pos=i;
    }
  }
  return pos;
}

/*查找指定学号的学生（顺序查找！）*/
void search(int sno[],float score[]) {
  char found,cont;
  int i,no;
  do {
    printf("输入待查询的学号： ");
    scanf("%d",&no);
    found='N';
    i=0;
    while (found=='N' && i<NUM) {
      if (sno[i]==no) {
        found='Y';
        printf("找到！学生[%d]的成绩为：%5.1f\n",sno[i],score[i]);
      }
      i++;
    }
    if (found=='N') printf("没有该学号的学生!\n");
    printf("继续查找吗(y/n)?");
    getchar();
    cont=getchar();
  } while (cont=='y' || cont=='Y');
}

/*学生学号按从小到大排序*/
void sort_sno(int sno[],float score[]) {
  float temp;
  short pos,min,tmp;
  for (int i=0;i<NUM-1;i++) {
    min=sno[i];  pos=i;
    for (int j=i+1;j<NUM;j++)
      if (sno[j]<min) { min=sno[j]; pos=j; }
      if (pos!=i) {
        tmp=sno[pos]; sno[pos]=sno[i]; sno[i]=tmp;
        temp=score[pos]; score[pos]=score[i]; score[i]=temp;
      }
  }
}

/*输出学生成绩表，含学号，成绩*/
void print(int sno[],float score[]) {
  printf("\n学生成绩表:\n");
  printf("%5s%8s\n","学号","成绩");
  for (int i=0;i<NUM;i++)
    printf("%5d%8.1f%\n",sno[i],score[i]);
}

/*查找指定学号的学生（二分法查找！递归过程）*/
void biquery(int sno[],float score[],int no,int low,int high) {
  int mid;  /*中间位置*/
  mid=(low+high)/2;
  if (sno[mid]==no) { //正好找到！
    printf("找到！学生[%d]的成绩为：%5.1f\n",sno[mid],score[mid]);
    return ;
  }
  else
    if (low<high) { //还没有找完！
      if (no>sno[mid]) //有一定在后一半！
        biquery(sno,score,no,mid+1,high);
      else             //有一定在前一半！
        biquery(sno,score,no,low,mid-1);
    }
    else { //全部找过，没有要找的学号！
      printf("没有该学号的学生!\n");
      return;
    }
}

/*学生成绩按从高到低排序*/
void sort_score(int sno[],float score[]) {
  float temp;
  short tmp;
  for (int i=0;i<NUM-1;i++) 
    for (int j=0;j<NUM-i-1;j++)
      if (score[j]<score[j+1]) {
        /*swap sno[j]/score[j] and sno[j+1]/score[j+1]*/
        tmp=sno[j]; sno[j]=sno[j+1]; sno[j+1]=tmp;
        temp=score[j]; score[j]=score[j+1]; score[j+1]=temp;
      }
}

//输入数据：101 78.5 102 88 103 65  104 93.5 105 64 106 59 107 84.5 108 70 109 76 110 73.5