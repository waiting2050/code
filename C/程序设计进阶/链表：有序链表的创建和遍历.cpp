//��������Ĵ����ͱ���
#include <stdio.h>
#include <malloc.h>

struct Student {
  int    sno;		        //ѧ��
  float  score;		      //�ɼ�
  struct Student *next;	//ָ����һ�����
};

//��һ�����������в�������(��Ȼ��������)
void insert(int sno,float score,Student * head);
//����ı�����ͳ�ơ����
void print_chain(Student * head);
//�ͷ�����
void free_chain(Student * head);

int main() {
  Student *head;
  int sno;
  float score;
  
  //�γ�ͷ���
  head=(Student *)malloc(sizeof(Student));
  head->next=NULL;
  
  printf("������ѧ����ѧ�źͳɼ�(����q����)��\n");
  while (scanf("%d%f",&sno,&score)==2) {
    //��һ�����������в�������(��Ȼ��������)
    insert(sno,score,head);
  }
  while (getchar()!='\n'); //������һ�������
  
  //����ı�����ͳ�ơ����
  print_chain(head);
  
  //�ͷ�����
  free_chain(head);
  
  return 0;
}

//��һ�����������в�������(��Ȼ��������)
void insert(int sno,float score,Student * head) {
  Student *n,*p,*q;
  //�γɴ�����Ľ��
  n=(Student *)malloc(sizeof(Student));
  n->sno=sno;  n->score=score;
  //�ҵ�����λ��
  p=head;
  q=p->next;
  while (q!=NULL && sno>q->sno) {
    p=q;q=p->next;
  }
  //������
  n->next=q;
  p->next=n;
}

//����ı�����ͳ�ơ����
void print_chain(Student * head) {
  Student *p;
  int n=0; //ͳ��ѧ������
  p=head->next;
  if (p!=NULL) {
    printf("���������Ϊ��\n");
    do {
      n++;
      printf("  [%5d  %.1f]\n",p->sno,p->score);
      p=p->next;
    } while (p!=NULL);
    printf("ѧ������Ϊ��%d\n\n",n);
  }
  else printf("����Ϊ��!\n");
}

//�ͷ�����
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
������ѧ����ѧ�źͳɼ�(����q����)��
107 88
104 66
105 87
101 74
103 99
q
���������Ϊ��
  [  101  74.0]
  [  103  99.0]
  [  104  66.0]
  [  105  87.0]
  [  107  88.0]
ѧ������Ϊ��5
****************************************/