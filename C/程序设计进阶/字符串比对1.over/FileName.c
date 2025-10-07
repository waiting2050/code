//你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，而且第一个字符串的长度小于第二个字符串的。
//你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出 - 1。

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define maxchar 10000

int main()
{
	printf("请输入两个字符串\n");
	char A[maxchar];
	char a[maxchar];
	gets(a);
	gets(A);

	int flag = 1;
	if (strstr(A, a) == '\0') {
		printf("无重合部分");
		flag = 0;
	}

	int length = strlen(A);

	char* p = A;
	while (flag) {
		p=strstr(p, a);
		if (p == '\0')
			break;
		int len = strlen(p);
		printf("%d\t", length - len);
		p++;
	}

	return 0;
}
