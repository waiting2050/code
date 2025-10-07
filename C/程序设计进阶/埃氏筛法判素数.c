#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int prime[200] = { 0 };//   0表示是素数，1不是 
	for (int i = 2; i <= n / i; i++)
	{
		if (!prime[i])
		{
			for (int j = i * i; j <= n; j += i)
				prime[j] = 1;
		}
	}

	return 0;
}

