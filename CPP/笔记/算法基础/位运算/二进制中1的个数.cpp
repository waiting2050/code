#include <iostream>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	while(n--)
	{
		ll a; cin >> a;
		int cnt = 0;
		const int mask = 1;

		while (a > 0)
		{
			if (a & mask)cnt++;
			a >>= 1;
		}

		cout << cnt << ' ';
	}

	return 0;
}
