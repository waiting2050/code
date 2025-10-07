#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int c[N];

//计数排序
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)//输入几个i，c[i]就加几。比如输入2个0，则c[0]=2。
	{
		int x; cin >> x;
		c[x]++;
	}

	for (int i = 0; i <= 2e5; i++)//在输入的数值范围内遍历
	{
		for (int j = 0; j < c[i]; j++)//c[i]即i这个数有几个，从0到这个数，有几个就输出几次i
			cout << i << ' ';
	}

	cout << '\n';

	return 0;
}
