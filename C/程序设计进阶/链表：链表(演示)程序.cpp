//链表(演示)程序

#include <stdio.h>
#include <malloc.h> //malloc
#include <string.h> //strcmp

//定义一些程序中使用到的常量
enum { 
  NO_LEN=8,         //学号的位数
  NAME_LEN=10,      //姓名的长度
  SCORE_NUM=2,      //课程数
  NO_MEM=-1,        //没有足够的内存
  INPUT_NUM_ERR=-2, //输入的(学生)项数不大于0
  NO_ITEM=-3        //学号不存在，无法进行插入
};

//定义(学生)项的结构(类型)
struct Item {
  char no[NO_LEN+1];         //学号(字符串)
  char name[NAME_LEN+1];     //姓名
  //性别、出生日期......
  double score[SCORE_NUM+1]; //N门课的成绩，总分
};

//定义(链表的)结点结构(类型)
struct Node {
  Item item;
  Node * next;
};

//功能：创建一个新的(学生)项(结点)，返回该结点的指针
Node * newItem(void) {
  Node *p;
  if ((p=(Node *)malloc(sizeof(Node)))==NULL) {
    printf("申请空间失败！\n");
    return NULL;
  }
  
  printf("输入学生的学号 姓名：");
  scanf("%s %s",p->item.no,p->item.name);
  
  printf("输入学生的%d门课的成绩：",SCORE_NUM);
  double sum=0; //总分
  for (int i=0;i<SCORE_NUM;i++) {
    scanf("%lf",&p->item.score[i]);
    sum+=p->item.score[i];      //计算总分
  }
  p->item.score[SCORE_NUM]=sum; //总分
  
  p->next=NULL;
  return p;
}

//功    能：输出一个(学生)项(结点)
//入口参数：p指向待输出的(学生)项(结点)
void printItem(Node *p) {
  printf("%-*s %-*s",NO_LEN,p->item.no,NAME_LEN,p->item.name);
  for (int i=0;i<=SCORE_NUM;i++) {
    printf(" %4.1lf",p->item.score[i]);
  }
  putchar('\n');
}

//功能：初始化链表，返回链表哨兵结点的指针或NULL(空间不足)
Node *initList(void) {
  Node *p;
  if ((p=(Node *)malloc(sizeof(Node)))==NULL) {
    printf("申请空间失败！\n");
    return NULL;
  }
  //哨兵结点的(学生)项数据留空！
  p->next=NULL; //表示链尾！
  return p;
}

//功    能：判链表是否为空链表，是返回真
//入口参数：head指向链表哨兵结点的指针
int isEmptyList(Node * head) {
  return (head->next==NULL);
}

//功能：从键盘输入(学生)项的数目并返回
int getItemNum(void) {
  int n;
  printf("输入学生数(>0)：");
  scanf("%d",&n);
  if (n<=0) printf("学生数<=0！\n");
  return n;
}

//功    能：将(学生)项(结点)加到链表的最前面
//入口参数：head指向链表哨兵结点的指针
//入口参数：newNode指向待插入的(学生)项(结点)
void addFront(Node * head,Node *newNode) {
  newNode->next=head->next;
  head->next=newNode;
}

//功    能：将(学生)项(结点)加到链表的末尾
//入口参数：head指向链表哨兵结点的指针
//入口参数：newNode指向待插入的(学生)项(结点)
void addEnd(Node * head,Node *newNode) {
  //先找到链尾
  for (Node *p=head;p->next!=NULL;p=p->next);
  
  p->next=newNode;
  //newNode->next=p->next;
}

//功    能：创建一个(无序)的链表，返回成功(0)或失败(<0)
//入口参数：head指向链表哨兵结点的指针
int creatList(Node * head) {
  int itemNum;
  if ((itemNum=getItemNum())<=0) 
    return INPUT_NUM_ERR; //创建链表失败
  
  Node *newNode;
  
  //创建一个新的(学生)项(结点)，并直接加至链表哨兵结点的后面
  for (int i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM;
    addFront(head,newNode);
  }
  
  //创建一个新的(学生)项(结点)，并加至链表的末尾
  for (i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM; 
    addEnd(head,newNode); 
  }
  
  return 0;
}

//功    能：统计链表的(学生)项(结点)总数
//入口参数：head指向链表哨兵结点的指针
int countList(Node * head) {
  int cnt=0;
  for (Node *p=head->next;p!=NULL;p=p->next)
    cnt++;
  return cnt;
}

//功    能：输出整个链表
//入口参数：head指向链表哨兵结点的指针
//返    回：0链表为空，1链表非空
int printList(Node * head) {
  if (isEmptyList(head)) {
    printf("链表为空！\n");
    return 0;
  }
  
  printf("学生成绩如下：\n");
  for (Node *p=head->next;p!=NULL;p=p->next) 
    printItem(p);
  
  return 1;
}

//功    能：在链表中查找指定学号的(学生)项(结点)
//入口参数：head指向链表哨兵结点的指针
//入口参数：no学生的学号
//返 回 值：指向指定学号的(学生)项(结点)的指针，或NULL没有找到该学生
Node * lookupItem(Node * head,char no[]) {
  //链表遍历的惯用法！正如数组的语句：for (int i=0;i<N;i++)
  for (Node *p=head->next;p!=NULL;p=p->next) {
    if (!strcmp(p->item.no,no)) return p;
  }
  return NULL;
}

//功    能：在链表中按学生学号进行查找
//入口参数：head指向链表哨兵结点的指针
void lookup(Node * head) {
  char no[NO_LEN+1];
  printf("\n输入待查询学生的学号（Quit结束查询）：");
  while (1) {
    scanf("%s",no);
    if (!strcmp(no,"Quit")) break;
    if (Node * p=lookupItem(head,no))
      printf("学号[%s]存在，其姓名为：%s，总分为：%-4.1lf！\n",no,p->item.name,p->item.score[SCORE_NUM]);
    else
      printf("学号[%s]不存在！\n",no);
    printf("输入待查询的下一个学生的学号：");
  }
}

//功    能：在链表中删除指定学号的(学生)项(结点)
//入口参数：head指向链表哨兵结点的指针
//入口参数：no学生的学号
//返 回 值：1成功删除，0没有找到该学生
int eraseItem(Node * head,char no[]) {
  Node *p,*prev;
  //遍历链表，同时记住前后2个指针
  
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {
      prev->next=p->next;  //断链
      free(p);             //释放被删除的结点
      return 1;
    }
  }
  
  return 0;
}

//功    能：在链表中按学生学号进行删除
//入口参数：head指向链表哨兵结点的指针
void erase(Node * head) {
  char no[NO_LEN+1];
  printf("\n输入待删除学生的学号（Quit结束查询）：");
  while (1) {
    scanf("%s",no);
    if (!strcmp(no,"Quit")) break;
    if (eraseItem(head,no)) 
      printf("学号[%s]的信息已经被成功删除！\n",no);
    else 
      printf("学号[%s]不存在！\n",no);
    printf("输入待删除的下一个学生的学号：");
  }
}

//功    能：(无序)链表的拷贝
//入口参数：head指向链表哨兵结点的指针
//返 回 值：指向拷贝生成的新链表的哨兵结点的指针
//          或NULL(内存不足)
Node * copyList(Node * head) {
  Node *newHead; //哨兵结点
  //初始化链表
  if ((newHead =initList())==NULL) 
    return NULL; //没有足够的内存，申请空间失败！
  
  for (Node *p=head->next;p!=NULL;p=p->next) {
    Node *newNode;
    if ((newNode=(Node *)malloc(sizeof(Node)))==NULL) {
      printf("申请空间失败！\n");
      return NULL;
    }
    else {
      *newNode=*p; //拷贝数据(会同时拷贝链表的指针)
      //自己生成新链表的链，否则链接到原有链表的结点
      newNode->next=newHead->next;
      newHead->next=newNode;
    }
  }
  
  return newHead;
}

//功    能：根据分裂结点的学生的学号将链表一分为二。
//入口参数：head指向链表哨兵结点的指针
//返 回 值：指向第二个链表的哨兵结点的指针
//          或NULL(没有找到该学生)
Node * splitList(Node * head) {
  char no[NO_LEN+1];
  printf("\n输入分裂结点的学生的学号：");
  scanf("%s",no);
  
  Node *p,*prev;
  //遍历链表，同时记住前后2个指针
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {      
      Node *newHead; //哨兵结点
      if ((newHead =initList())==NULL) //初始化链表
        return NULL; //没有足够的内存，申请空间失败！
      prev->next=NULL; //断链
      newHead->next=p; //生成新链表
      printf("按指定的结点成功将链表一分为二！\n");
      return newHead;
    }
  }
  
  printf("分裂结点的学生的学号不存在。分裂失败！\n");
  return NULL;
}

//功    能：在指定结点的前面插入新的(学生)项(结点)
//入口参数：head指向链表哨兵结点的指针
//返 回 值：0成功插入，其他值(没有找到指定的学生)
int insertBefore(Node * head) {
  char no[NO_LEN+1];
  printf("\n输入要在那个学生(学号)的前面插入：");
  scanf("%s",no);
  
  Node *p,*prev;
  //遍历链表，同时记住前后2个指针
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {
      Node * newNode;
      if ((newNode=newItem())==NULL) return NO_MEM;
      //接链
      prev->next=newNode;
      newNode->next=p;
      printf("结点已经成功被插入在指定结点的前面！\n");
      return 0;
    }
  }
  
  printf("输入的学生的学号不存在。插入失败！\n");
  return NO_ITEM;
}

//功    能：在指定结点的后面插入新的(学生)项(结点)
//入口参数：head指向链表哨兵结点的指针
//返 回 值：0成功插入，其他值(没有找到指定的学生)
int insertAfter(Node * head) {
  char no[NO_LEN+1];
  printf("\n输入要在那个学生(学号)的后面插入：");
  scanf("%s",no);
  
  Node *p;
  if ((p=lookupItem(head,no))==NULL) {
    printf("输入的学生的学号不存在。插入失败！\n");
    return NO_ITEM;
  }
  
  Node *newNode;
  if ((newNode=newItem())==NULL) return NO_MEM;
  
  newNode->next=p->next;  //接链
  p->next=newNode;
  
  printf("结点已经成功被插入在指定结点的后面！\n");
  return 0; 
}

//功    能：链表翻转(不能建立新的表来实现)
//入口参数：head指向链表哨兵结点的指针
void reverseList(Node * head) {
  Node *p=head->next;
  head->next=NULL;
  while (p!=NULL) {
    Node *cur=p;
    p=p->next;
    cur->next=head->next;
    head->next=cur;
  }
}

//功    能：合并两个(无序)链表
//入口参数：h1、h2分别指向2个(无序)链表的哨兵结点的指针
void mergeList(Node * h1,Node * h2) {
  //先找到第1条链表的链尾
  for (Node *p=h1;p->next!=NULL;p=p->next);
  
  p->next=h2->next; //合并两个链表
  free(h2);         //释放第2个链表的哨兵结点
}

//功    能：合并两个有序链表，结果仍然保持有序(即：归并排序)
//入口参数：h1、h2分别指向2个有序链表的哨兵结点的指针
void mergeOrderList(Node * h1,Node * h2) {
  if (!isEmptyList(h2)) {
    Node *prev1=h1,*p1=h1->next;
    Node *next2;
    for (Node *p2=h2->next;p2!=NULL;p2=next2) {
      next2=p2->next;
      for (;p1!=NULL;prev1=p1,p1=p1->next) {
        if (strcmp(p1->item.no,p2->item.no)>0) //已经找到了插入位置
          break;
      }
      //接链，完成新结点的插入
      prev1->next=p2;
      p2->next=p1;
      prev1=p2;
    }
  }
  free(h2);
}

//功    能：释放链表
//入口参数：head指向链表哨兵结点的指针
void freeList(Node * head) {
  Node * next;
  for (Node *p=head;p!=NULL;p=next) {
    next=p->next; //务必先记住其下一个结点
    free(p);      //然后才能释放该结点，否则会出现悬空指针
  }
}

//功    能：在一个有序链表中插入一个新的结点，插入后保持有序
//入口参数：head指向有序链表的哨兵结点的指针
void insertOrderList(Node * head,Node * newNode) {
  Node *p,*prev;
  //遍历链表，同时记住前后2个指针
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (strcmp(p->item.no,newNode->item.no)>0) //已经找到了插入位置
      break;
  }
  //接链，完成新结点的插入
  prev->next=newNode;
  newNode->next=p;
  return;
}

//功    能：创建一个(有序)的链表，返回成功0或失败(<0)
//入口参数：head指向有序链表哨兵结点的指针
int creatOrderList(Node * head) {
  int itemNum;
  if ((itemNum=getItemNum())<=0) 
    return INPUT_NUM_ERR; //创建链表失败
  
  Node *newNode;
  //创建一个新的(学生)项(结点)，并插入一个有序链表中
  for (int i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM;
    insertOrderList(head,newNode);
  }
 
  return 0;
}

int main() {
  int ret;
  
  Node * head;                  //链表的头指针  
  if ((head=initList())==NULL) //初始化链表(创建哨兵结点)
    return NO_MEM;              //没有足够的内存，申请空间失败！
  
  //创建一个(无序)的链表
  if (ret=creatList(head)) {
    freeList(head);         //释放链表
    return ret;             //用户输入非法的学生数或申请空间失败！
  }
  
  printf("\n共有%d个学生！\n\n",countList(head));
  
  printList(head);          //输出链表
  
  lookup(head);             //链表查找
  
  erase(head);              //链表删除
  
  printList(head);          //输出链表
  
  //在指定结点的前面插入
  if (ret=insertBefore(head)) {
    freeList(head);         //释放链表
    return ret;             //用户输入非法的学生数或申请空间失败！
  }
  printList(head);          //输出链表
  
  //在指定结点的后面插入
  if (ret=insertAfter(head)) {
    freeList(head);         //释放链表
    return ret;             //用户输入非法的学生数或申请空间失败！
  }
  printList(head);          //输出链表
  
  Node *newHead;
  //链表的拷贝(生成一个一样的链表)
  if ((newHead =copyList(head))==NULL) 
    return NO_MEM;          //没有足够的内存，申请空间失败！
  printf("\n拷贝生成的链表 ，");
  printList(newHead);       //输出链表
  
  mergeList(head,newHead);  //合并两个(无序)链表
  printf("\n合并后的链表，");
  printList(head);          //输出链表
  
  //根据分裂结点的学生的学号将链表一分为二
  if ((newHead=splitList(head))==NULL) {
    return NO_ITEM;         //用户输入的学生不存在或申请空间失败！
  }
  printList(head);          //输出链表1
  printList(newHead);       //输出链表2
  freeList(newHead);        //释放链表2 
  
  printf("\n翻转前的链表 ，");
  printList(head);          //输出链表
  reverseList(head);        //链表翻转
  printf("翻转后的链表 ，");
  printList(head);          //输出链表
  freeList(head);           //释放链表

  putchar('\n');
  if ((head=initList())==NULL) //初始化链表
    return NO_MEM;             //没有足够的内存，申请空间失败！
  //创建一个(有序)的链表
  if (ret=creatOrderList(head)) {
    freeList(head);         //释放链表
    return ret;             //用户输入非法的学生数或申请空间失败！
  }
  printf("\n该有序链表共有%d个学生！\n\n",countList(head));
  printList(head);          //输出链表

  if ((newHead=initList())==NULL) //初始化链表
    return NO_MEM;                //没有足够的内存，申请空间失败！
  //创建一个(有序)的链表
  if (ret=creatOrderList(newHead)) {
    freeList(newHead);      //释放链表
    return ret;             //用户输入非法的学生数或申请空间失败！
  }
  printf("\n该有序链表共有%d个学生！\n\n",countList(newHead));
  printList(newHead);       //输出链表
  
  //合并两个有序链表，结果仍然保持有序(即：归并排序)
  mergeOrderList(head,newHead);
  printf("\n两个有序链表合并后共有%d个学生！\n\n",countList(head));
  printf("合并后的链表，");
  printList(head);          //输出链表

  freeList(head);           //释放链表
 
  return 0;
}

/*
输入的测试数据：
3
10000001 周千万
77 65
10000002 李讷
98 55
10000003 王林芙蓉
69 78
10000004 朱新生
84 62
10000005 陈冯赫德
90 73
10000006 赵大龙之谷
81 94
10000004
10000002
10000000
Quit
10000004
10000000
Quit
10000005
10000007 张八一
88 74
10000002
10000008 钱宝军
48 69
10000006
3
10000004 朱新生
84 62
10000007 张八一
88 74
10000001 周千万
77 65
5
10000005 陈冯赫德
90 73
10000003 王林芙蓉
69 78
10000008 钱宝军
48 69
10000002 李讷
98 55
10000006 赵大龙之谷
81 94
*/
