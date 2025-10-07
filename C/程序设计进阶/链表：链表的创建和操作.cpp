//����Ĵ��������������ҡ�����(���)��ɾ��(���)���ϲ����ͷ�
//û�н����κ����������Եļ���

#include <stdio.h>
#include <malloc.h>

struct StudentType {
  int    sno;		            //ѧ��
  float  score;		          //�ɼ�
  struct StudentType *next;	//ָ����һ�����
};

//�����Ƚ��ȳ���������(��������)
StudentType * create_chain1(void);
//��������ȳ���������(ջstack)
StudentType * create_chain2(void);
//����ı�����ͳ�ơ����
void print_chain(StudentType * head);
//�������
void chain_lookup(StudentType * head,int sno);
//(����ǰ)����һ�����
void insert_node1(StudentType * head);
//������β׷��һ�����
void insert_node2(StudentType * head);
//ɾ������һ�����(�����Ȳ�������)
void delete_node(StudentType * head);
//�ϲ������������������������ͷָ��ֱ�Ϊhead1��head2
void merge_chain(StudentType * head1,StudentType * head2);
//�ͷ�����
void free_chain(StudentType * head);

int main() {
  StudentType *head,*head2;
  
  //�����Ƚ��ȳ���������(��������)
  head=create_chain1();

  //��������ȳ���������(ջstack)
  head2=create_chain2();

  //�ϲ���������������
  merge_chain(head,head2);
  
  //����ı�����ͳ�ơ����
  print_chain(head);
  
  printf("����������ҵ�ѧ����ѧ�ţ�");
  int sno;
  scanf("%d",&sno);
  //�������
  chain_lookup(head,sno);
  
  //(����ǰ)����һ�����
  insert_node1(head);
  //����ı�����ͳ�ơ����
  print_chain(head);
  
  //������β׷��һ�����
  insert_node2(head);
  //����ı�����ͳ�ơ����
  print_chain(head);
  
  //ɾ������һ�����(�����Ȳ�������)
  delete_node(head);
  //����ı�����ͳ�ơ����
  print_chain(head);
  
  //�ͷ�����
  free_chain(head);
  
  return 0;
}

//�����Ƚ��ȳ���������(��������)
StudentType * create_chain1(void) {
  StudentType *head,*last,*n;
  int sno;
  float score;
  
  head=last=(StudentType *)malloc(sizeof(StudentType));
  //headͷ�ڵ��������Ϊ�գ�
  //lastָ���������һ�����
  
  printf("������ѧ����ѧ�źͳɼ�(����q����)��\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //����һ���½�㲢������������
    n=(StudentType *)malloc(sizeof(StudentType));
    n->sno=sno;
    n->score=score;

    last->next=n; //���½��ӵ��������
    last=n;       //��β��Ϊ�ռ�����½��  
  }

  last->next=NULL; //���Ѿ�������nextָ����ΪNULL
  
  while (getchar()!='\n'); //����q���ַ���ֱ����һ�������
  
  return head;
}

//��������ȳ���������(ջstack)
StudentType * create_chain2(void) {
  StudentType *head,*n;
  int sno;
  float score;
  
  head=(StudentType *)malloc(sizeof(StudentType));
  //head ͷ�ڵ��������Ϊ�գ�
  head->next=NULL;
  
  printf("������ѧ����ѧ�źͳɼ�(����q����)��\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //����һ���½�㲢������������
    n=(StudentType *)malloc(sizeof(StudentType));
    n->sno=sno;
    n->score=score;

    n->next=head->next; //�½��ָ����ͷ��next���
    head->next=n;       //���½��ӵ���ͷ��
  }
  
  while (getchar()!='\n'); //����q���ַ���ֱ����һ�������
  
  return head;
}

//�ϲ������������������������ͷָ��ֱ�Ϊhead1��head2
void merge_chain(StudentType * head1,StudentType * head2) {
  StudentType * last,*q;

  //�ҵ���1��������β
  last=head1;
  q=last->next;
  while (q!=NULL) {
    last=q;
    q=last->next;
  }

  //�ϲ���������
  last->next=head2->next;

  //�ͷŵ�2�������ͷָ��
  free(head2);
}

//����ı�����ͳ�ơ����
void print_chain(StudentType * head) {
  StudentType *p;
  int n=0; //ͳ��ѧ������
  printf("��ͷ�ĵ�ַ�ǣ�%p����next���ŵĵ�ַ�ǣ�%p\n\n",head,head->next);
  p=head->next;
  if (p!=NULL) {
    printf("���������Ϊ��\n");
    do {
      n++;
      printf("  {%p->%p}[%5d  %.1f]\n",p,p->next,p->sno,p->score);
      p=p->next;
    } while (p!=NULL);
    printf("ѧ������Ϊ��%d\n\n",n);
  }
  else printf("����Ϊ��!\n");
}

//�������(�����������)
void chain_lookup(StudentType * head,int sno) {
  StudentType *p;
  char found='N';
  p=head->next;
  while (found=='N' && p!=NULL) {
    if (p->sno==sno) found='Y';
    else p=p->next;
  }
  if (found=='Y') 
    printf("�ҵ���[%5d  %.1f]\n",p->sno,p->score);
  else printf("ѧ��[%d]û���ҵ�!\n",sno);
}

//(����ǰ)����һ�����
//���ַ�ʽ�Ĳ���ͱ�ɺ���ȳ�(ջstack)
void insert_node1(StudentType * head) {
  StudentType *p;
  p=(StudentType *)malloc(sizeof(StudentType));
  
  printf("\n������������(����ǰ)ѧ����ѧ�źͳɼ���");
  scanf("%d%f",&p->sno,&p->score);
  
  p->next=head->next;
  head->next=p;
}

//������β׷��һ�����
void insert_node2(StudentType * head) {
  StudentType *p,*q,*last;
  p=(StudentType *)malloc(sizeof(StudentType));
  
  printf("\n��������(������β)׷��ѧ����ѧ�źͳɼ���");
  scanf("%d%f",&p->sno,&p->score);
  
  last=head;		//�ҵ���βָ��
  q=last->next;
  while (q!=NULL) {
    last=q;
    q=last->next;
  }
  p->next=NULL;
  last->next=p;
}

//ɾ������һ�����(�����Ȳ�������)
void delete_node(StudentType * head) {
  int sno;
  printf("��������ɾ��ѧ����ѧ�ţ�");
  scanf("%d",&sno);
  
  char found='N';
  StudentType *p,*q;
  
  p=head;
  q=p->next;
  while (found=='N' && q!=NULL) {
    if (q->sno==sno) {
      found='Y';       //��ֹѭ��
      p->next=q->next; //������
      free(q);         //�ͷŽ��
    }
    else { p=q;q=p->next; }
  }
  if (found=='N') printf("ѧ��[%d]û���ҵ�!\n",sno);
}

//�ͷ�����
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
�����ѧ���������£�
101 68
103 77.5
104 98
106 54

102 70
105 83.5
107 85
***********************/