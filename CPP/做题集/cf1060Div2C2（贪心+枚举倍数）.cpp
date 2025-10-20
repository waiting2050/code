// Problem: CF 2154 C2
// Contest: Codeforces - Codeforces Round 1060 (Div. 2)
// URL: https://codeforces.com/contest/2154/problem/C2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 只需要有一个gcd(ai,aj)>1即可，假设b数组所有代价相同,那么最多只需要两次操作即可达成条件,因为任意两个偶数一定有公因子2
// 但是b的代价不相同,但是思路是差不多的，可以根据操作次数分类。  
// 1.不用操作：本身a数组就有gcd>1，代价为0；      2.操作一次：某个数+1以后，有gcd>1
// 3.操作次数>=2，给两个数分别+1，一定可以gcd>1，（两个偶数在条件1讨论了，1奇1偶在条件2讨论了，此时可将两个数看为奇数）
// 或者给1个数加>=2次。那么到底给哪个数加几次呢？一定是代价最小的数，加几次枚举得到。
// 因为前提给两个数分别+1，一定可以gcd>1，设代价最小的两个数b[1,2],有k*bi>=b1+b2(k>=2)，因此一定是枚举b1
// 观察到本题ai<=2e5，一个常见的思路是将枚举因数转为枚举倍数来降低复杂度，用埃氏筛枚举倍数获得每个数的因数
// 复杂度大概是nlogn

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

struct P
{
	int a, b;
	
	bool operator<(const P& t) const
	{
		return b < t.b;
	}
}p[N];

vector<int> g[N];
bitset<N> vis;

void solve()
{
	vis.reset();
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i].a;
	for(int i = 1; i <= n; i++) cin >> p[i].b;
	sort(p + 1, p + 1 + n);
	
    // 情况1，操作次数为0
	for(int i = 1; i <= n; i++)
	{
		for(auto& y : g[p[i].a])
		{
			if(vis[y])
			{
				cout << 0 << '\n';
				return;
			}
			vis[y] = 1;
		}
	}
	// 情况2，操作次数为1
	ll ans = p[1].b + p[2].b; 
	for(int i = 1; i <= n; i++)
		for(auto& y : g[p[i].a + 1])
			if(vis[y]) ans = min(ans, (ll)p[i].b);
    // ps：不会存在ai+1以后受ai因子影响的情况，连续整数的最大公约数一定是 1，gcd(x,x+1)=1
    // 因此不必考虑质因数冲突
	
	for(int i = 2; i <= n; i++)
	{
		for(auto& y : g[p[i].a])
		{
			int times = y - (p[1].a % y);
			ans = min(ans, 1ll * times * p[1].b);
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	for(int i = 2; i < N; i++)
	{
		if(g[i].size()) continue;
		for(int j = i; j <= N; j += i) g[j].push_back(i);
	}
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 6
// 2
// 1 1
// 1 2
// 2
// 4 8
// 41 67
// 5
// 1 1 727 1 1
// 1 1 1000 1 1
// 2
// 3 11
// 1 1
// 3
// 2 7 11
// 1 6 6
// 3
// 2 7 11
// 100 1 2
// 
// 3
// 0
// 2
// 1
// 5
// 1