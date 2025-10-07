//�򵥵�ѧ��ѧ������ϵͳ(�������Ƴɼ�)
#include <stdio.h>
#include <math.h>

#define NUM 10     /*ѧ��������*/

/*����ѧ����ѧ�źͳɼ�*/
void input (int sno[],float score[]);
/*���㲢���ƽ���ɼ�*/
float ave(float score[]);
/*ͳ�Ƹ������ε�����*/
void mark_sect(float score[],short g[5]);
/*�����߷ֶ�Ӧ���±�*/
int get_max_index(float score[]);
/*����ָ��ѧ�ŵ�ѧ����˳����ң���*/
void search(int sno[],float score[]);
/*ѧ��ѧ�Ű���С��������*/
void sort_sno(int sno[],float score[]);
/*���ѧ���ɼ�����ѧ�ţ��ɼ�*/
void print(int sno[],float score[]);
/*����ָ��ѧ�ŵ�ѧ�������ַ����ң��ݹ���̣�*/
void biquery(int sno[],float score[],int no,int low,int high);
/*ѧ���ɼ����Ӹߵ�������*/
void sort_score(int sno[],float score[]);

int main() {
  int   sno[NUM];   /*����ѧ��ѧ��*/
  float score[NUM]; /*����ѧ���ɼ�*/
  
  /*����ѧ����ѧ�źͳɼ�*/
  input(sno,score);
  
  float aver=ave(score);
  printf("\nƽ���ɼ�Ϊ: %5.1f\n",aver);
  
  short grade[5]; /*����������ε�����*/
  mark_sect(score,grade);
  
  //����������ε�����
  printf("\n��������ε������ֱ�Ϊ��\n");
  for(int i=0;i<5;i++) printf("%c:%d  ",'A'+i,grade[i]);
  printf("\n");printf("\n");  //������� A:2  B:2  C:3  D:2  E:1
  
  /*���ѧ���ɼ�����ѧ�ţ��ɼ�����׼��*/
  printf("ѧ���ɼ���:\n");
  printf("%5s%8s%8s\n","ѧ��","�ɼ�","��׼��");
  for (i=0;i<NUM;i++)
    printf("%5d%8.1f%8.1f\n",sno[i],score[i],score[i]-aver);
  
  //�����߷ֵ�ѧ��
  int index=get_max_index(score); //�����߷ֶ�Ӧ���±�
  printf("\nѧ��[%d]�ĳɼ���%5.1fΪ��߷֣�\n\n",sno[index],score[index]);
  
  //����ָ��ѧ�ŵ�ѧ��
  search(sno,score);
  
  /*ѧ��ѧ�Ű��Ӵ�С����*/
  sort_sno(sno,score);
  /*���ѧ���ɼ�����ѧ�ţ��ɼ�*/
  print(sno,score);
  
  //����ָ��ѧ�ŵ�ѧ��
  printf("\n");
  int no;
  char cont;
  do {
    printf("�������ѯ��ѧ�ţ� ");
    scanf("%d",&no);
    biquery(sno,score,no,0,NUM-1);
    printf("����������(y/n)?");
    getchar();
    cont=getchar();
  } while (cont=='y' || cont=='Y');
  
  /*ѧ���ɼ����Ӹߵ�������*/
  sort_score(sno,score);
  
  /*���ѧ���ɼ�������*/
  printf("\nѧ���ɼ���:\n");
  printf("%5s %8s %4s\n","ѧ��","�ɼ�","����");
  int j=0/*����*/;
  float g=-1;
  for (i=0;i<NUM;i++) {
    if (g!=score[i]) {
      g=score[i];
      j=i+1;
    }
    printf("%5d %8.1f (%2d)\n",sno[i],score[i],j);
  }
} // END main

/*����ѧ����ѧ�źͳɼ�*/
void input (int sno[],float score[]) {
  printf("����%d��ѧ����ѧ�źͳɼ�:\n",NUM);
  for (int i=0;i<NUM;i++) 
    scanf("%d%f",&sno[i],&score[i]);
} //�����ʽ1001 70.5 1010 56 1003 88.5 1009 92 1002 64 1006 77 1008 63 1004 83.5 1007 70.5 1005 100

/*���㲢���ƽ���ɼ�*/
float ave(float score[]) {
  float ave=0;
  for(int i=0;i<NUM;i++) ave+=score[i];
  ave/=NUM;
  return ave;
}

/*ͳ�Ƹ������ε�����*/
void mark_sect(float score[],short g[5]) {
  for(int i=0;i<5;i++) g[i]=0; //�ó�ֵ
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

/*�����߷ֶ�Ӧ���±�*/
int get_max_index(float score[]) {
  float max=-1;
  short pos=-1;  /*��ʼ��*/
  for (int i=0;i<NUM;i++) {
    if (score[i]>max) {
      max=score[i];
      pos=i;
    }
  }
  return pos;
}

/*����ָ��ѧ�ŵ�ѧ����˳����ң���*/
void search(int sno[],float score[]) {
  char found,cont;
  int i,no;
  do {
    printf("�������ѯ��ѧ�ţ� ");
    scanf("%d",&no);
    found='N';
    i=0;
    while (found=='N' && i<NUM) {
      if (sno[i]==no) {
        found='Y';
        printf("�ҵ���ѧ��[%d]�ĳɼ�Ϊ��%5.1f\n",sno[i],score[i]);
      }
      i++;
    }
    if (found=='N') printf("û�и�ѧ�ŵ�ѧ��!\n");
    printf("����������(y/n)?");
    getchar();
    cont=getchar();
  } while (cont=='y' || cont=='Y');
}

/*ѧ��ѧ�Ű���С��������*/
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

/*���ѧ���ɼ�����ѧ�ţ��ɼ�*/
void print(int sno[],float score[]) {
  printf("\nѧ���ɼ���:\n");
  printf("%5s%8s\n","ѧ��","�ɼ�");
  for (int i=0;i<NUM;i++)
    printf("%5d%8.1f%\n",sno[i],score[i]);
}

/*����ָ��ѧ�ŵ�ѧ�������ַ����ң��ݹ���̣�*/
void biquery(int sno[],float score[],int no,int low,int high) {
  int mid;  /*�м�λ��*/
  mid=(low+high)/2;
  if (sno[mid]==no) { //�����ҵ���
    printf("�ҵ���ѧ��[%d]�ĳɼ�Ϊ��%5.1f\n",sno[mid],score[mid]);
    return ;
  }
  else
    if (low<high) { //��û�����꣡
      if (no>sno[mid]) //��һ���ں�һ�룡
        biquery(sno,score,no,mid+1,high);
      else             //��һ����ǰһ�룡
        biquery(sno,score,no,low,mid-1);
    }
    else { //ȫ���ҹ���û��Ҫ�ҵ�ѧ�ţ�
      printf("û�и�ѧ�ŵ�ѧ��!\n");
      return;
    }
}

/*ѧ���ɼ����Ӹߵ�������*/
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

//�������ݣ�101 78.5 102 88 103 65  104 93.5 105 64 106 59 107 84.5 108 70 109 76 110 73.5