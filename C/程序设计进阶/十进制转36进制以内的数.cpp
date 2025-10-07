#include <stdio.h>
#include <stdlib.h>

void decimal_to_base(int n, int base, char* result) 
{
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = 0;
    int temp = n;

    if (n == 0) 
    {
        result[index++] = '0';
    }
    else 
    {
        while (temp > 0) 
        {
            result[index++] = digits[temp % base];
            temp /= base;
        }
    }
    result[index] = '\0';

    for (int i = 0; i < index / 2; i++) 
    {
        char swap = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = swap;
    }
}

int main() 
{
    int cnt;
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) 
    {
        int number, base;
        scanf("%d %d", &number, &base);

        char result[65];
        decimal_to_base(number, base, result);

        printf("%s[%d]\n", result, base);
    }

    return 0;
}
