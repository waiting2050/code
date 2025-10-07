//二维数组作为函数参数的参数传递方式
#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int a[][COLS],int rows);  //二维数组作为参数的正常传递方式
void sum_cols(int [][COLS],int);        //原型声明可以省略变量名
int sum_all(int (*a)[COLS],int rows);   //另一种形式可以，但在这种场合并不好

int main() {
  int mat[][COLS]={
    {2,4,6,8},
    {3,5,7,9},
    {1,1,1,1}
  };
  sum_rows(mat,ROWS);putchar('\n');
  sum_cols(mat,ROWS);putchar('\n');
  printf("所有元素的和为：%d\n",sum_all(mat,ROWS));
}

void sum_rows(int a[][COLS],int rows) {
  int sum;
  for (int r=0;r<rows;r++) {
    sum=0;
    for (int c=0;c<COLS;c++) sum+=a[r][c];
    printf("第%d行的和为：%d\n",r+1,sum);
  }
}

void sum_cols(int a[][COLS],int rows) { //这个地方可不能再省略变量名
  int sum;
  for (int c=0;c<COLS;c++) {
    sum=0;
    for (int r=0;r<rows;r++) sum+=a[r][c];
    printf("第%d列的和为：%d\n",c+1,sum);
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