//�����������ַ�����ÿ���ַ���ռ��һ�У�ÿ���ַ����ĳ��Ⱦ�С��10000�ַ������ҵ�һ���ַ����ĳ���С�ڵڶ����ַ����ġ�
//��ĳ���Ҫ�ҳ���һ���ַ����ڵڶ����ַ����г��ֵ�λ�ã������Щλ�ã�����Ҳ���������� - 1��

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define maxchar 10000

int main()
{
	printf("�����������ַ���\n");
	char A[maxchar];
	char a[maxchar];
	gets(a);
	gets(A);

	int flag = 1;
	if (strstr(A, a) == '\0') {
		printf("���غϲ���");
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
