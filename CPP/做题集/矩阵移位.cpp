//描述
//
//对以下5*5矩阵实现行列循环移位：
//
//1 2 3 4 5
//
//6 7 8 9 10
//
//11 12 13 14 15
//
//16 17 18 19 20
//
//21 22 23 24 25
//
//输入两个整数，
//
//第一个整数为行循环移动的行数，正数表示向下循环移动，负数表示向上循环移动。
//
//第二个整数为列循环移动的列数，正数表示向右循环移动，负数表示向左循环移动。
//
//比如：2 -3
//
//表示矩阵先按行向下循环移动2行，再向左循环移动3列。
//
//
//输入
//
//输入两个整数，用空格隔开。
//
//
//输出
//
//按题目形式输出矩阵，矩阵中的每个元素的宽度为6。
//
//
//输入样例 1 
//
//2 -3
//输出样例 1
//
//    19    20    16    17    18
//    24    25    21    22    23
//     4     5     1     2     3
//     9    10     6     7     8
//    14    15    11    12    13
#include <stdio.h>

int main() 
{
    int matrix[5][5], temp[5][5];
    int row_shift, col_shift;

    int num = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = num++;

    scanf("%d %d", &row_shift, &col_shift);

    row_shift = ((row_shift % 5) + 5) % 5;
    col_shift = ((col_shift % 5) + 5) % 5;

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            temp[i][j] = matrix[(i - row_shift + 5) % 5][j];

    for (int i = 0; i < 5; i++) 
        for (int j = 0; j < 5; j++) 
            matrix[i][j] = temp[i][(j - col_shift + 5) % 5];

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++)
            printf("%6d", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
