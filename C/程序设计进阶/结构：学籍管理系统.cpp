//��ʾ�ṹ�����ʹ�ã��ǳ��򵥵�ѧ��ϵͳ��
#include <stdio.h>

#define N 6          //ѧ����
#define NAME_SIZE 14 //�����7������

enum SexType {male,female}; //�Ա�

struct Student {            //ѧ���ṹ(����)
  int   num;                //ѧ��(ʵ��ϵͳӦ������ַ���)
  char  name[NAME_SIZE+1];  //����
  enum  SexType sex;        //�Ա�
  short age;                //����(ʵ��ϵͳӦ����ɳ�������)
  float score;              //�ɼ�(ʵ��ϵͳһ�㲻����ô��)
}; 

/*����ѧ����Ϣ(�����Ƶĳ���)*/
void input(Student st[]);
/*���ɼ��Ӹߵ�������*/
void sort(Student st[]);
/*���ѧ����Ϣ*/
void print(Student st[]);

//������֡��ֶ���֮����˼�룡
int main() {
  struct Student students[N];
  /*����ѧ����Ϣ*/
  input(students);
  /*���ɼ��Ӹߵ�������*/
  sort(students);
  /*���ѧ����Ϣ*/
  print(students);
}

/*����ѧ����Ϣ(�����Ƶĳ���)*/
void input(Student st[]) {
  char c; //����Ա��ַ�(f��m)
  printf("������ѧ��,����,�Ա�(f��m),����,�ɼ���\n");
  for (int i=0;i<N;i++) {
    scanf("%d %s %c %d %f",&st[i].num,st[i].name,&c,&st[i].age,&st[i].score);
    st[i].sex=((c=='m')?male:female);
  }
}

/*���ɼ��Ӹߵ���������һ����ʽ��ð������*/
void sort(Student st[]) {
  struct Student temp;
  for (int i=0;i<N-1;i++)
    for (int j=i+1;j<N;j++)
      if (st[i].score<st[j].score) {
        temp=st[i]; //�ṹ����ֱ�Ӹ�ֵ
        st[i]=st[j];
        st[j]=temp;
      }
}

/*���ѧ����Ϣ*/
void print(Student st[]) {
  printf("%8s%16s%8s%8s%8s\n",
    "ѧ��","����","�Ա�","����","�ɼ�");
  for (int i=0;i<N;i++) {
    printf("%8d%16s",st[i].num,st[i].name);
    if (st[i].sex==male) printf("%8s","��");
    else printf("%8s","Ů");
    printf("%8hd%8.1f\n",st[i].age,st[i].score);
  }
}

/*
��������(ѧ��,����,�Ա�(f��m),����,�ɼ�)��
1001 ���� f 20 86
1002 ���� m 19 77
1003 ���� m 21 95
1004 ������ f 20 87
1005 ����ǿ m 18 68
1006 ����һ m 22 91
*/
