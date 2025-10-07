//链表的创建、遍历、查找、插入(结点)、删除(结点)、合并、释放
//没有进行任何数据完整性的检验

#include <stdio.h>
#include <malloc.h>

struct StudentType {
  int    sno;		            //学号
  float  score;		          //成绩
  struct StudentType *next;	//指向下一个结点
};

//建立先进先出单向链表(即：队列)
StudentType * create_chain1(void);
//建立后进先出单向链表(栈stack)
StudentType * create_chain2(void);
//链表的遍历、统计、输出
void print_chain(StudentType * head);
//链表查找
void chain_lookup(StudentType * head,int sno);
//(链表前)插入一个结点
void insert_node1(StudentType * head);
//在链表尾追加一个结点
void insert_node2(StudentType * head);
//删除链表一个结点(必须先查找链表)
void delete_node(StudentType * head);
//合并两个（无序）链表，两个链表的头指针分别为head1和head2
void merge_chain(StudentType * head1,StudentType * head2);
//释放链表
void free_chain(StudentType * head);

int main() {
  StudentType *head,*head2;
  
  //建立先进先出单向链表(即：队列)
  head=create_chain1();

  //建立后进先出单向链表(栈stack)
  head2=create_chain2();

  //合并两个（无序）链表
  merge_chain(head,head2);
  
  //链表的遍历、统计、输出
  print_chain(head);
  
  printf("请输入待查找的学生的学号：");
  int sno;
  scanf("%d",&sno);
  //链表查找
  chain_lookup(head,sno);
  
  //(链表前)插入一个结点
  insert_node1(head);
  //链表的遍历、统计、输出
  print_chain(head);
  
  //在链表尾追加一个结点
  insert_node2(head);
  //链表的遍历、统计、输出
  print_chain(head);
  
  //删除链表一个结点(必须先查找链表)
  delete_node(head);
  //链表的遍历、统计、输出
  print_chain(head);
  
  //释放链表
  free_chain(head);
  
  return 0;
}

//建立先进先出单向链表(即：队列)
StudentType * create_chain1(void) {
  StudentType *head,*last,*n;
  int sno;
  float score;
  
  head=last=(StudentType *)malloc(sizeof(StudentType));
  //head头节点的数据域为空！
  //last指向链的最后一个结点
  
  printf("请输入学生的学号和成绩(输入q结束)：\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //申请一个新结点并存入读入的数据
    n=(StudentType *)malloc(sizeof(StudentType));
    n->sno=sno;
    n->score=score;

    last->next=n; //将新结点接到链的最后
    last=n;       //链尾改为刚加入的新结点  
  }

  last->next=NULL; //链已经结束，next指针置为NULL
  
  while (getchar()!='\n'); //跳过q等字符，直到下一个输入项！
  
  return head;
}

//建立后进先出单向链表(栈stack)
StudentType * create_chain2(void) {
  StudentType *head,*n;
  int sno;
  float score;
  
  head=(StudentType *)malloc(sizeof(StudentType));
  //head 头节点的数据域为空！
  head->next=NULL;
  
  printf("请输入学生的学号和成绩(输入q结束)：\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //申请一个新结点并存入读入的数据
    n=(StudentType *)malloc(sizeof(StudentType));
    n->sno=sno;
    n->score=score;

    n->next=head->next; //新结点指向链头的next结点
    head->next=n;       //将新结点接到链头后
  }
  
  while (getchar()!='\n'); //跳过q等字符，直到下一个输入项！
  
  return head;
}

//合并两个（无序）链表，两个链表的头指针分别为head1和head2
void merge_chain(StudentType * head1,StudentType * head2) {
  StudentType * last,*q;

  //找到第1条链的链尾
  last=head1;
  q=last->next;
  while (q!=NULL) {
    last=q;
    q=last->next;
  }

  //合并两个链表
  last->next=head2->next;

  //释放第2个链表的头指针
  free(head2);
}

//链表的遍历、统计、输出
void print_chain(StudentType * head) {
  StudentType *p;
  int n=0; //统计学生总数
  printf("表头的地址是：%p，其next域存放的地址是：%p\n\n",head,head->next);
  p=head->next;
  if (p!=NULL) {
    printf("链表的内容为：\n");
    do {
      n++;
      printf("  {%p->%p}[%5d  %.1f]\n",p,p->next,p->sno,p->score);
      p=p->next;
    } while (p!=NULL);
    printf("学生总数为：%d\n\n",n);
  }
  else printf("链表为空!\n");
}

//链表查找(必须遍历链表)
void chain_lookup(StudentType * head,int sno) {
  StudentType *p;
  char found='N';
  p=head->next;
  while (found=='N' && p!=NULL) {
    if (p->sno==sno) found='Y';
    else p=p->next;
  }
  if (found=='Y') 
    printf("找到：[%5d  %.1f]\n",p->sno,p->score);
  else printf("学号[%d]没有找到!\n",sno);
}

//(链表前)插入一个结点
//这种方式的插入就变成后进先出(栈stack)
void insert_node1(StudentType * head) {
  StudentType *p;
  p=(StudentType *)malloc(sizeof(StudentType));
  
  printf("\n请输入欲插入(链表前)学生的学号和成绩：");
  scanf("%d%f",&p->sno,&p->score);
  
  p->next=head->next;
  head->next=p;
}

//在链表尾追加一个结点
void insert_node2(StudentType * head) {
  StudentType *p,*q,*last;
  p=(StudentType *)malloc(sizeof(StudentType));
  
  printf("\n请输入欲(在链表尾)追加学生的学号和成绩：");
  scanf("%d%f",&p->sno,&p->score);
  
  last=head;		//找到链尾指针
  q=last->next;
  while (q!=NULL) {
    last=q;
    q=last->next;
  }
  p->next=NULL;
  last->next=p;
}

//删除链表一个结点(必须先查找链表)
void delete_node(StudentType * head) {
  int sno;
  printf("请输入欲删除学生的学号：");
  scanf("%d",&sno);
  
  char found='N';
  StudentType *p,*q;
  
  p=head;
  q=p->next;
  while (found=='N' && q!=NULL) {
    if (q->sno==sno) {
      found='Y';       //终止循环
      p->next=q->next; //断连接
      free(q);         //释放结点
    }
    else { p=q;q=p->next; }
  }
  if (found=='N') printf("学号[%d]没有找到!\n",sno);
}

//释放链表
void free_chain(StudentType * head) {
  StudentType *p,*q;
  p=head;
  while (p!=NULL) {
    q=p;
    p=p->next;
    free(q);
  }
}

/**********************
输入的学生数据如下：
101 68
103 77.5
104 98
106 54

102 70
105 83.5
107 85
***********************/