//描述
//
//输出一个字符串中的数值(数值溢出输出“overflow”)，每2个数值之间用空格分隔。 不要求处理符号。前导0不能输出，026应该输出26。 例如：
//
//输入：5Pw4e++3h1DdA--735b6)0NF002bye 输出：5 4 3 1 735 6 0 2
//
//
//输入
//
//一个全部由可打印字符组成的字符串（但含有<回车>和<换行>），长度可能很长。
//
//
//输出
//
//将该字符串中的所有数值分别输出，如果数值超过int可以表示的范围，则输出overflow，每2个数值之间用空格分隔。


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

void extractNumbers(const char* str) 
{
    const char* p = str;
    int isNumber = 0;
    long long num = 0;
    int hasOutput = 0;

    while (*p)
    {
        if (isdigit(*p))
        {
            if (!isNumber) 
            {
                isNumber = 1;
                num = 0;
            }
            num = num * 10 + (*p - '0');

            if (num > INT_MAX) 
            {
                while (isdigit(*p)) p++;
                if (hasOutput) printf(" ");
                printf("overflow");
                hasOutput = 1;
                isNumber = 0;
                continue;
            }
        }
        else 
        {
            if (isNumber) 
            {
                if (hasOutput) printf(" ");
                printf("%lld", num);
                hasOutput = 1;
                isNumber = 0;
            }
        }
        p++;
    }

    if (isNumber) 
    {
        if (hasOutput) printf(" ");
        printf("%lld", num);
    }
}

int main() 
{
    char input[1000];

    while (fgets(input, 1000, stdin) != NULL)
    {
        input[strcspn(input, "\n")] = '\0';

        extractNumbers(input);
    }

    return 0;
}
