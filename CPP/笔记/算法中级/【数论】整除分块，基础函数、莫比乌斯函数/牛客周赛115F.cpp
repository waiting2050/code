// Problem: 小苯的GCD疑问2.0
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/119895/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 看到题目第一反应是枚举gcd，sum肯定越大越好，那么尽可能全选即可，所以对每个gcd需要O(1)得到答案，但是枚举全部gcd是1e9的，考虑怎么去优化
// 举个例子，n=20时，若gcd=11，那么ans=11*20；若gcd=12,13...,ans=max(gcd)*20，既然这样，gcd直接取20就是最好的，所以发现某个数量对应的区间gcd是有最优情况的，
// 比如取1个时，20/1=20，gcd为20最优。这里就有整除分块的性质了，在每个数量的区间里，只计算最优gcd对应的ans，复杂度O(T√n)
// 怎么求区间呢？⌊n/gcd⌋是个数，那么⌊n/⌊n/gcd⌋⌋就是该区间最优的gcd

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

void solve()
{
	ll n, k; cin >> n >> k;
	
	ll ans = 0;
	for(ll l = 1, r; l <= n; l = r + 1)
	{
		ll cnt = n / l;
		if(cnt < k) break;
		r = n / cnt;
		ans = max(ans, r * r * (1 + cnt) * cnt / 2);
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 9 2
// 9 3

// 54
// 54