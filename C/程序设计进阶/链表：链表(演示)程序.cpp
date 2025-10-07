//����(��ʾ)����

#include <stdio.h>
#include <malloc.h> //malloc
#include <string.h> //strcmp

//����һЩ������ʹ�õ��ĳ���
enum { 
  NO_LEN=8,         //ѧ�ŵ�λ��
  NAME_LEN=10,      //�����ĳ���
  SCORE_NUM=2,      //�γ���
  NO_MEM=-1,        //û���㹻���ڴ�
  INPUT_NUM_ERR=-2, //�����(ѧ��)����������0
  NO_ITEM=-3        //ѧ�Ų����ڣ��޷����в���
};

//����(ѧ��)��Ľṹ(����)
struct Item {
  char no[NO_LEN+1];         //ѧ��(�ַ���)
  char name[NAME_LEN+1];     //����
  //�Ա𡢳�������......
  double score[SCORE_NUM+1]; //N�ſεĳɼ����ܷ�
};

//����(�����)���ṹ(����)
struct Node {
  Item item;
  Node * next;
};

//���ܣ�����һ���µ�(ѧ��)��(���)�����ظý���ָ��
Node * newItem(void) {
  Node *p;
  if ((p=(Node *)malloc(sizeof(Node)))==NULL) {
    printf("����ռ�ʧ�ܣ�\n");
    return NULL;
  }
  
  printf("����ѧ����ѧ�� ������");
  scanf("%s %s",p->item.no,p->item.name);
  
  printf("����ѧ����%d�ſεĳɼ���",SCORE_NUM);
  double sum=0; //�ܷ�
  for (int i=0;i<SCORE_NUM;i++) {
    scanf("%lf",&p->item.score[i]);
    sum+=p->item.score[i];      //�����ܷ�
  }
  p->item.score[SCORE_NUM]=sum; //�ܷ�
  
  p->next=NULL;
  return p;
}

//��    �ܣ����һ��(ѧ��)��(���)
//��ڲ�����pָ��������(ѧ��)��(���)
void printItem(Node *p) {
  printf("%-*s %-*s",NO_LEN,p->item.no,NAME_LEN,p->item.name);
  for (int i=0;i<=SCORE_NUM;i++) {
    printf(" %4.1lf",p->item.score[i]);
  }
  putchar('\n');
}

//���ܣ���ʼ���������������ڱ�����ָ���NULL(�ռ䲻��)
Node *initList(void) {
  Node *p;
  if ((p=(Node *)malloc(sizeof(Node)))==NULL) {
    printf("����ռ�ʧ�ܣ�\n");
    return NULL;
  }
  //�ڱ�����(ѧ��)���������գ�
  p->next=NULL; //��ʾ��β��
  return p;
}

//��    �ܣ��������Ƿ�Ϊ�������Ƿ�����
//��ڲ�����headָ�������ڱ�����ָ��
int isEmptyList(Node * head) {
  return (head->next==NULL);
}

//���ܣ��Ӽ�������(ѧ��)�����Ŀ������
int getItemNum(void) {
  int n;
  printf("����ѧ����(>0)��");
  scanf("%d",&n);
  if (n<=0) printf("ѧ����<=0��\n");
  return n;
}

//��    �ܣ���(ѧ��)��(���)�ӵ��������ǰ��
//��ڲ�����headָ�������ڱ�����ָ��
//��ڲ�����newNodeָ��������(ѧ��)��(���)
void addFront(Node * head,Node *newNode) {
  newNode->next=head->next;
  head->next=newNode;
}

//��    �ܣ���(ѧ��)��(���)�ӵ������ĩβ
//��ڲ�����headָ�������ڱ�����ָ��
//��ڲ�����newNodeָ��������(ѧ��)��(���)
void addEnd(Node * head,Node *newNode) {
  //���ҵ���β
  for (Node *p=head;p->next!=NULL;p=p->next);
  
  p->next=newNode;
  //newNode->next=p->next;
}

//��    �ܣ�����һ��(����)���������سɹ�(0)��ʧ��(<0)
//��ڲ�����headָ�������ڱ�����ָ��
int creatList(Node * head) {
  int itemNum;
  if ((itemNum=getItemNum())<=0) 
    return INPUT_NUM_ERR; //��������ʧ��
  
  Node *newNode;
  
  //����һ���µ�(ѧ��)��(���)����ֱ�Ӽ��������ڱ����ĺ���
  for (int i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM;
    addFront(head,newNode);
  }
  
  //����һ���µ�(ѧ��)��(���)�������������ĩβ
  for (i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM; 
    addEnd(head,newNode); 
  }
  
  return 0;
}

//��    �ܣ�ͳ�������(ѧ��)��(���)����
//��ڲ�����headָ�������ڱ�����ָ��
int countList(Node * head) {
  int cnt=0;
  for (Node *p=head->next;p!=NULL;p=p->next)
    cnt++;
  return cnt;
}

//��    �ܣ������������
//��ڲ�����headָ�������ڱ�����ָ��
//��    �أ�0����Ϊ�գ�1����ǿ�
int printList(Node * head) {
  if (isEmptyList(head)) {
    printf("����Ϊ�գ�\n");
    return 0;
  }
  
  printf("ѧ���ɼ����£�\n");
  for (Node *p=head->next;p!=NULL;p=p->next) 
    printItem(p);
  
  return 1;
}

//��    �ܣ��������в���ָ��ѧ�ŵ�(ѧ��)��(���)
//��ڲ�����headָ�������ڱ�����ָ��
//��ڲ�����noѧ����ѧ��
//�� �� ֵ��ָ��ָ��ѧ�ŵ�(ѧ��)��(���)��ָ�룬��NULLû���ҵ���ѧ��
Node * lookupItem(Node * head,char no[]) {
  //��������Ĺ��÷��������������䣺for (int i=0;i<N;i++)
  for (Node *p=head->next;p!=NULL;p=p->next) {
    if (!strcmp(p->item.no,no)) return p;
  }
  return NULL;
}

//��    �ܣ��������а�ѧ��ѧ�Ž��в���
//��ڲ�����headָ�������ڱ�����ָ��
void lookup(Node * head) {
  char no[NO_LEN+1];
  printf("\n�������ѯѧ����ѧ�ţ�Quit������ѯ����");
  while (1) {
    scanf("%s",no);
    if (!strcmp(no,"Quit")) break;
    if (Node * p=lookupItem(head,no))
      printf("ѧ��[%s]���ڣ�������Ϊ��%s���ܷ�Ϊ��%-4.1lf��\n",no,p->item.name,p->item.score[SCORE_NUM]);
    else
      printf("ѧ��[%s]�����ڣ�\n",no);
    printf("�������ѯ����һ��ѧ����ѧ�ţ�");
  }
}

//��    �ܣ���������ɾ��ָ��ѧ�ŵ�(ѧ��)��(���)
//��ڲ�����headָ�������ڱ�����ָ��
//��ڲ�����noѧ����ѧ��
//�� �� ֵ��1�ɹ�ɾ����0û���ҵ���ѧ��
int eraseItem(Node * head,char no[]) {
  Node *p,*prev;
  //��������ͬʱ��סǰ��2��ָ��
  
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {
      prev->next=p->next;  //����
      free(p);             //�ͷű�ɾ���Ľ��
      return 1;
    }
  }
  
  return 0;
}

//��    �ܣ��������а�ѧ��ѧ�Ž���ɾ��
//��ڲ�����headָ�������ڱ�����ָ��
void erase(Node * head) {
  char no[NO_LEN+1];
  printf("\n�����ɾ��ѧ����ѧ�ţ�Quit������ѯ����");
  while (1) {
    scanf("%s",no);
    if (!strcmp(no,"Quit")) break;
    if (eraseItem(head,no)) 
      printf("ѧ��[%s]����Ϣ�Ѿ����ɹ�ɾ����\n",no);
    else 
      printf("ѧ��[%s]�����ڣ�\n",no);
    printf("�����ɾ������һ��ѧ����ѧ�ţ�");
  }
}

//��    �ܣ�(����)����Ŀ���
//��ڲ�����headָ�������ڱ�����ָ��
//�� �� ֵ��ָ�򿽱����ɵ���������ڱ�����ָ��
//          ��NULL(�ڴ治��)
Node * copyList(Node * head) {
  Node *newHead; //�ڱ����
  //��ʼ������
  if ((newHead =initList())==NULL) 
    return NULL; //û���㹻���ڴ棬����ռ�ʧ�ܣ�
  
  for (Node *p=head->next;p!=NULL;p=p->next) {
    Node *newNode;
    if ((newNode=(Node *)malloc(sizeof(Node)))==NULL) {
      printf("����ռ�ʧ�ܣ�\n");
      return NULL;
    }
    else {
      *newNode=*p; //��������(��ͬʱ���������ָ��)
      //�Լ�����������������������ӵ�ԭ������Ľ��
      newNode->next=newHead->next;
      newHead->next=newNode;
    }
  }
  
  return newHead;
}

//��    �ܣ����ݷ��ѽ���ѧ����ѧ�Ž�����һ��Ϊ����
//��ڲ�����headָ�������ڱ�����ָ��
//�� �� ֵ��ָ��ڶ���������ڱ�����ָ��
//          ��NULL(û���ҵ���ѧ��)
Node * splitList(Node * head) {
  char no[NO_LEN+1];
  printf("\n������ѽ���ѧ����ѧ�ţ�");
  scanf("%s",no);
  
  Node *p,*prev;
  //��������ͬʱ��סǰ��2��ָ��
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {      
      Node *newHead; //�ڱ����
      if ((newHead =initList())==NULL) //��ʼ������
        return NULL; //û���㹻���ڴ棬����ռ�ʧ�ܣ�
      prev->next=NULL; //����
      newHead->next=p; //����������
      printf("��ָ���Ľ��ɹ�������һ��Ϊ����\n");
      return newHead;
    }
  }
  
  printf("���ѽ���ѧ����ѧ�Ų����ڡ�����ʧ�ܣ�\n");
  return NULL;
}

//��    �ܣ���ָ������ǰ������µ�(ѧ��)��(���)
//��ڲ�����headָ�������ڱ�����ָ��
//�� �� ֵ��0�ɹ����룬����ֵ(û���ҵ�ָ����ѧ��)
int insertBefore(Node * head) {
  char no[NO_LEN+1];
  printf("\n����Ҫ���Ǹ�ѧ��(ѧ��)��ǰ����룺");
  scanf("%s",no);
  
  Node *p,*prev;
  //��������ͬʱ��סǰ��2��ָ��
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (!strcmp(p->item.no,no)) {
      Node * newNode;
      if ((newNode=newItem())==NULL) return NO_MEM;
      //����
      prev->next=newNode;
      newNode->next=p;
      printf("����Ѿ��ɹ���������ָ������ǰ�棡\n");
      return 0;
    }
  }
  
  printf("�����ѧ����ѧ�Ų����ڡ�����ʧ�ܣ�\n");
  return NO_ITEM;
}

//��    �ܣ���ָ�����ĺ�������µ�(ѧ��)��(���)
//��ڲ�����headָ�������ڱ�����ָ��
//�� �� ֵ��0�ɹ����룬����ֵ(û���ҵ�ָ����ѧ��)
int insertAfter(Node * head) {
  char no[NO_LEN+1];
  printf("\n����Ҫ���Ǹ�ѧ��(ѧ��)�ĺ�����룺");
  scanf("%s",no);
  
  Node *p;
  if ((p=lookupItem(head,no))==NULL) {
    printf("�����ѧ����ѧ�Ų����ڡ�����ʧ�ܣ�\n");
    return NO_ITEM;
  }
  
  Node *newNode;
  if ((newNode=newItem())==NULL) return NO_MEM;
  
  newNode->next=p->next;  //����
  p->next=newNode;
  
  printf("����Ѿ��ɹ���������ָ�����ĺ��棡\n");
  return 0; 
}

//��    �ܣ�����ת(���ܽ����µı���ʵ��)
//��ڲ�����headָ�������ڱ�����ָ��
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

//��    �ܣ��ϲ�����(����)����
//��ڲ�����h1��h2�ֱ�ָ��2��(����)������ڱ�����ָ��
void mergeList(Node * h1,Node * h2) {
  //���ҵ���1���������β
  for (Node *p=h1;p->next!=NULL;p=p->next);
  
  p->next=h2->next; //�ϲ���������
  free(h2);         //�ͷŵ�2��������ڱ����
}

//��    �ܣ��ϲ������������������Ȼ��������(�����鲢����)
//��ڲ�����h1��h2�ֱ�ָ��2������������ڱ�����ָ��
void mergeOrderList(Node * h1,Node * h2) {
  if (!isEmptyList(h2)) {
    Node *prev1=h1,*p1=h1->next;
    Node *next2;
    for (Node *p2=h2->next;p2!=NULL;p2=next2) {
      next2=p2->next;
      for (;p1!=NULL;prev1=p1,p1=p1->next) {
        if (strcmp(p1->item.no,p2->item.no)>0) //�Ѿ��ҵ��˲���λ��
          break;
      }
      //����������½��Ĳ���
      prev1->next=p2;
      p2->next=p1;
      prev1=p2;
    }
  }
  free(h2);
}

//��    �ܣ��ͷ�����
//��ڲ�����headָ�������ڱ�����ָ��
void freeList(Node * head) {
  Node * next;
  for (Node *p=head;p!=NULL;p=next) {
    next=p->next; //����ȼ�ס����һ�����
    free(p);      //Ȼ������ͷŸý�㣬������������ָ��
  }
}

//��    �ܣ���һ�����������в���һ���µĽ�㣬����󱣳�����
//��ڲ�����headָ������������ڱ�����ָ��
void insertOrderList(Node * head,Node * newNode) {
  Node *p,*prev;
  //��������ͬʱ��סǰ��2��ָ��
  for (prev=head,p=prev->next;p!=NULL;prev=p,p=p->next) {
    if (strcmp(p->item.no,newNode->item.no)>0) //�Ѿ��ҵ��˲���λ��
      break;
  }
  //����������½��Ĳ���
  prev->next=newNode;
  newNode->next=p;
  return;
}

//��    �ܣ�����һ��(����)���������سɹ�0��ʧ��(<0)
//��ڲ�����headָ�����������ڱ�����ָ��
int creatOrderList(Node * head) {
  int itemNum;
  if ((itemNum=getItemNum())<=0) 
    return INPUT_NUM_ERR; //��������ʧ��
  
  Node *newNode;
  //����һ���µ�(ѧ��)��(���)��������һ������������
  for (int i=0;i<itemNum;i++) {
    if ((newNode=newItem())==NULL) return NO_MEM;
    insertOrderList(head,newNode);
  }
 
  return 0;
}

int main() {
  int ret;
  
  Node * head;                  //�����ͷָ��  
  if ((head=initList())==NULL) //��ʼ������(�����ڱ����)
    return NO_MEM;              //û���㹻���ڴ棬����ռ�ʧ�ܣ�
  
  //����һ��(����)������
  if (ret=creatList(head)) {
    freeList(head);         //�ͷ�����
    return ret;             //�û�����Ƿ���ѧ����������ռ�ʧ�ܣ�
  }
  
  printf("\n����%d��ѧ����\n\n",countList(head));
  
  printList(head);          //�������
  
  lookup(head);             //�������
  
  erase(head);              //����ɾ��
  
  printList(head);          //�������
  
  //��ָ������ǰ�����
  if (ret=insertBefore(head)) {
    freeList(head);         //�ͷ�����
    return ret;             //�û�����Ƿ���ѧ����������ռ�ʧ�ܣ�
  }
  printList(head);          //�������
  
  //��ָ�����ĺ������
  if (ret=insertAfter(head)) {
    freeList(head);         //�ͷ�����
    return ret;             //�û�����Ƿ���ѧ����������ռ�ʧ�ܣ�
  }
  printList(head);          //�������
  
  Node *newHead;
  //����Ŀ���(����һ��һ��������)
  if ((newHead =copyList(head))==NULL) 
    return NO_MEM;          //û���㹻���ڴ棬����ռ�ʧ�ܣ�
  printf("\n�������ɵ����� ��");
  printList(newHead);       //�������
  
  mergeList(head,newHead);  //�ϲ�����(����)����
  printf("\n�ϲ��������");
  printList(head);          //�������
  
  //���ݷ��ѽ���ѧ����ѧ�Ž�����һ��Ϊ��
  if ((newHead=splitList(head))==NULL) {
    return NO_ITEM;         //�û������ѧ�������ڻ�����ռ�ʧ�ܣ�
  }
  printList(head);          //�������1
  printList(newHead);       //�������2
  freeList(newHead);        //�ͷ�����2 
  
  printf("\n��תǰ������ ��");
  printList(head);          //�������
  reverseList(head);        //����ת
  printf("��ת������� ��");
  printList(head);          //�������
  freeList(head);           //�ͷ�����

  putchar('\n');
  if ((head=initList())==NULL) //��ʼ������
    return NO_MEM;             //û���㹻���ڴ棬����ռ�ʧ�ܣ�
  //����һ��(����)������
  if (ret=creatOrderList(head)) {
    freeList(head);         //�ͷ�����
    return ret;             //�û�����Ƿ���ѧ����������ռ�ʧ�ܣ�
  }
  printf("\n������������%d��ѧ����\n\n",countList(head));
  printList(head);          //�������

  if ((newHead=initList())==NULL) //��ʼ������
    return NO_MEM;                //û���㹻���ڴ棬����ռ�ʧ�ܣ�
  //����һ��(����)������
  if (ret=creatOrderList(newHead)) {
    freeList(newHead);      //�ͷ�����
    return ret;             //�û�����Ƿ���ѧ����������ռ�ʧ�ܣ�
  }
  printf("\n������������%d��ѧ����\n\n",countList(newHead));
  printList(newHead);       //�������
  
  //�ϲ������������������Ȼ��������(�����鲢����)
  mergeOrderList(head,newHead);
  printf("\n������������ϲ�����%d��ѧ����\n\n",countList(head));
  printf("�ϲ��������");
  printList(head);          //�������

  freeList(head);           //�ͷ�����
 
  return 0;
}

/*
����Ĳ������ݣ�
3
10000001 ��ǧ��
77 65
10000002 ��ګ
98 55
10000003 ����ܽ��
69 78
10000004 ������
84 62
10000005 �·�յ�
90 73
10000006 �Դ���֮��
81 94
10000004
10000002
10000000
Quit
10000004
10000000
Quit
10000005
10000007 �Ű�һ
88 74
10000002
10000008 Ǯ����
48 69
10000006
3
10000004 ������
84 62
10000007 �Ű�һ
88 74
10000001 ��ǧ��
77 65
5
10000005 �·�յ�
90 73
10000003 ����ܽ��
69 78
10000008 Ǯ����
48 69
10000002 ��ګ
98 55
10000006 �Դ���֮��
81 94
*/
