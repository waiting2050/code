#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll a[N], w[N], prefix[N];//a表示动物（代号0或1），w表示重量, prefix表示偏移量
					
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
		for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (a[i] ? -1 : 1) * w[i];//a[i] = 0是鼠鼠，修改后要加上重量，1本来是鸭鸭，修改后减去

		ll fix = 0, mi = 0;				//fix是偏移量，也就是改变的重量
		for (int i = 1; i <= n; i++)
		{
			fix = max(fix, prefix[i] - mi);//prefix[i] - mi即prefix[r] - prefix[l - 1],求一段区间增加的最大。//r对应的prefix要最大,l对应的要最小
			mi = min(mi, prefix[i]);			//用fix，mi存储之前比较后的变量并继续比较//在循环中，fix，mi不断更新，最后得到区间内变化量的最大最小
		}

		cout << ess + fix << '\n';
	}

	return 0;
}
