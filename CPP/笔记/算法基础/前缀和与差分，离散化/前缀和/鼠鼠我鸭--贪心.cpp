#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll a[N], w[N];//a表示动物（代号0或1），w表示重量, prefix表示偏移量
					
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> w[i];

		ll ess = 0;				//ess是基本量，也就是修改前的鸭鸭重量。
		for (int i = 1; i <= n; i++) ess += a[i] * w[i];

		ll fix = 0, mx = 0;			//fix是偏移量，也就是改变的重量
		for (int i = 1; i <= n; i++)
		{
			mx = max(0ll, mx + (a[i] ? -1 : 1) * w[i]);//运用到了贪心的思想，让偏移量依次计算，一旦加和小于0，就让mx归0
			fix = max(fix, mx);							//用fix储存最大偏移量
		}

		cout << ess + fix << '\n';
	}

	return 0;
}
