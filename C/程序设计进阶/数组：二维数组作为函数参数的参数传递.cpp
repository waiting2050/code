//��ά������Ϊ���������Ĳ������ݷ�ʽ
#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int a[][COLS],int rows);  //��ά������Ϊ�������������ݷ�ʽ
void sum_cols(int [][COLS],int);        //ԭ����������ʡ�Ա�����
int sum_all(int (*a)[COLS],int rows);   //��һ����ʽ���ԣ��������ֳ��ϲ�����

int main() {
  int mat[][COLS]={
    {2,4,6,8},
    {3,5,7,9},
    {1,1,1,1}
  };
  sum_rows(mat,ROWS);putchar('\n');
  sum_cols(mat,ROWS);putchar('\n');
  printf("����Ԫ�صĺ�Ϊ��%d\n",sum_all(mat,ROWS));
}

void sum_rows(int a[][COLS],int rows) {
  int sum;
  for (int r=0;r<rows;r++) {
    sum=0;
    for (int c=0;c<COLS;c++) sum+=a[r][c];
    printf("��%d�еĺ�Ϊ��%d\n",r+1,sum);
  }
}

void sum_cols(int a[][COLS],int rows) { //����ط��ɲ�����ʡ�Ա�����
  int sum;
  for (int c=0;c<COLS;c++) {
    sum=0;
    for (int r=0;r<rows;r++) sum+=a[r][c];
    printf("��%d�еĺ�Ϊ��%d\n",c+1,sum);
  }
}

int sum_all(int (*a)[COLS],int rows) {
  int sum=0;
  for (int r=0;r<rows;r++) {
    for (int c=0;c<COLS;c++) 
      sum+=a[r][c];
  }
  return sum;
}