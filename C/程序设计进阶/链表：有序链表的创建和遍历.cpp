//有序链表的创建和遍历
#include <stdio.h>
#include <malloc.h>

struct Student {
  int    sno;		        //学号
  float  score;		      //成绩
  struct Student *next;	//指向下一个结点
};

//在一个有序链表中插入数据(仍然保持有序)
void insert(int sno,float score,Student * head);
//链表的遍历、统计、输出
void print_chain(Student * head);
//释放链表
void free_chain(Student * head);

int main() {
  Student *head;
  int sno;
  float score;
  
  //形成头结点
  head=(Student *)malloc(sizeof(Student));
  head->next=NULL;
  
  printf("请输入学生的学号和成绩(输入q结束)：\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //在一个有序链表中插入数据(仍然保持有序)
    insert(sno,score,head);
  }
  while (getchar()!='\n'); //跳到下一个输入项！
  
  //链表的遍历、统计、输出
  print_chain(head);
  
  //释放链表
  free_chain(head);
  
  return 0;
}

//在一个有序链表中插入数据(仍然保持有序)
void insert(int sno,float score,Student * head) {
  Student *n,*p,*q;
  //形成待插入的结点
  n=(Student *)malloc(sizeof(Student));
  n->sno=sno;  n->score=score;
  //找到插入位置
  p=head;
  q=p->next;
  while (q!=NULL && sno>q->sno) {
    p=q;q=p->next;
  }
  //插入结点
  n->next=q;
  p->next=n;
}

//链表的遍历、统计、输出
void print_chain(Student * head) {
  Student *p;
  int n=0; //统计学生总数
  p=head->next;
  if (p!=NULL) {
    printf("链表的内容为：\n");
    do {
      n++;
      printf("  [%5d  %.1f]\n",p->sno,p->score);
      p=p->next;
    } while (p!=NULL);
    printf("学生总数为：%d\n\n",n);
  }
  else printf("链表为空!\n");
}

//释放链表
void free_chain(Student * head) {
  Student *p,*q;
  p=head;
  while (p!=NULL) {
    q=p;
    p=p->next;
    free(q);
  }
}

/****************************************
请输入学生的学号和成绩(输入q结束)：
107 88
104 66
105 87
101 74
103 99
q
链表的内容为：
  [  101  74.0]
  [  103  99.0]
  [  104  66.0]
  [  105  87.0]
  [  107  88.0]
学生总数为：5
****************************************/