#include <iostream>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			int a; cin >> a;
			
			temp ^= a;
		}

		cout << temp << '\n';
	}

	return 0;
}
