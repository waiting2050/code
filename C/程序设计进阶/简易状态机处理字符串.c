//����
//
//���һ���ַ����е���ֵ(��ֵ��������overflow��)��ÿ2����ֵ֮���ÿո�ָ��� ��Ҫ������š�ǰ��0���������026Ӧ�����26�� ���磺
//
//���룺5Pw4e++3h1DdA--735b6)0NF002bye �����5 4 3 1 735 6 0 2
//
//
//����
//
//һ��ȫ���ɿɴ�ӡ�ַ���ɵ��ַ�����������<�س�>��<����>�������ȿ��ܺܳ���
//
//
//���
//
//�����ַ����е�������ֵ�ֱ�����������ֵ����int���Ա�ʾ�ķ�Χ�������overflow��ÿ2����ֵ֮���ÿո�ָ���


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
