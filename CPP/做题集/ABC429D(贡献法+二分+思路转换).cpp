// Problem: AT ABC429 D
// Contest: AtCoder - Polaris.AI Programming Contest 2025（AtCoder Beginner Contest 429）Polaris.AI 编程竞赛 2025（AtCoder 入门竞赛 429）
// URL: https://atcoder.jp/contests/abc429/tasks/abc429_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题最直观的思路是对每一个距离，往后去找，到哪个点人数符合要求。但是这样明显会超时，那不如反过来，对每个人，
// 往后找到符合人数要求时距离是多少。但是这样只能求某个人对答案的贡献，会遗漏没有人的点对答案的贡献
// 怎么计算无人点的贡献呢？可以发现无人点的贡献与他前一个有人的点的贡献是相同的，于是只要知道两个有人点间有多少无人点即可
// 将有人/无人点贡献求和即为答案

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 5e5 + 7;

ll a[N << 1];

void solve()
{
	ll n, m, c; cin >> n >> m >> c;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);	
	for(int i = 1; i <= n; i++) a[i + n] = a[i] + m;
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
        // 用upper_bound，因为停止的点若有多人，全部计入
		int p = upper_bound(a + 1, a + 1 + 2 * n, a[i + c]) - a - 1;
		ans += 1ll * (p - i) * (a[i + 1] - a[i]); // p-i：有多少人，a[i+1]-a[i]:有多少点贡献相同
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5 3 2
// 1 2 1 0 1

// 9


// 1 1000000000000 1
// 1

// 1000000000000