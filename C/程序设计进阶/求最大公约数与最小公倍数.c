#include <stdio.h>

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int a = gcd(4, 6);
	int b = lcm(4, 6);
	printf("%d %d", a, b);
	
	return 0;
}
