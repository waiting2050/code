// Problem: CF 2156 D
// Contest: Codeforces - Codeforces Round 1061 (Div. 2)
// URL: https://codeforces.com/contest/2156/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 既然每次查找&的结果，那么将每个数拆位，每次询问只询问某1位上的数是0还是1，对n-1个数都询问一次
// 再对n个数检查一次，如果询问里1的个数和检查里1的个数一样，说明缺少的第n位为0，反之为1
// 这样最多需要询问 n-1 + (n-1)/2 + (n-1)/4 + ... 看作调和级数求和，次数一定小于2n

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

int query(int id, int x)
{
	cout << '?' << ' ' << id << ' ' << x << endl;
	int res; cin >> res;
	
	return res;
}

void solve()
{
	int n; cin >> n;
	
    // 注意本题核心：维护两个集合，缺少第n位元素的待询问元素集，完全的n位排列集
	vector<int> req, rmn;
    for(int i = 1; i < n; i++) req.pb(i);
    for(int i = 1; i <= n; i++) rmn.pb(i);
	
	int lim = log2(n), ans = 0;
	for(int i = 0; i <= lim; i++)
	{
		vector<int> cc1, cc0;
		for(auto& y : req)
		{
			int t = query(y, 1 << i);
			if(t) cc1.pb(y);
			else cc0.pb(y);
		}
		
		vector<int> cnt0, cnt1;
		for(auto& y : rmn)
		{
			if(y >> i & 1) cnt1.pb(y);
			else cnt0.pb(y);
		}
		
		if(cc1.size() == cnt1.size())
		{
			req = move(cc0);
			rmn = move(cnt0);
		}
		else
		{
			req = move(cc1);
			rmn = move(cnt1);
			ans |= 1 << i;
		}
	}
	
	cout << '!' << ' ' << ans << endl;
}

int main()
{
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 2
// 2 1
// 3
// 1 3 2

// 1
// 2