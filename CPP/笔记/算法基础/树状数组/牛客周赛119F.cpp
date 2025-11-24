// Problem: 小苯的极大支配
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/122724/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题思路很直接，如果一个数是最大支配数，那么首先将数值比他大的删去，再将数值小于它但是频次大于它的删去，不必全删，
// 删到频次比它小1即可，在代码中可以找需要保留多少数，用总数-保留就得到待删除数了

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e6 + 7;

// 树状数组 (Sum)：ts[k] 维护频次为 k 的数字的总频次之和
// 树状数组 (Count)：tc[k] 维护频次为 k 的不同数字的种类数
int a[N], c[N], ts[N], n, tc[N];

int lowbit(int x) {return x & -x;}

int querys(int k)
{
	int res = 0;
	for(int i = k; i > 0; i -= lowbit(i)) res += ts[i];
	
	return res;
}

void updates(int k, int x)
{
	for(int i = k; i <= n; i += lowbit(i)) ts[i] += x;
}

int queryc(int k)
{
	int res = 0;
	for(int i = k; i > 0; i -= lowbit(i)) res += tc[i];
	
	return res;
}

void updatec(int k, int x)
{
	for(int i = k; i <= n; i += lowbit(i)) tc[i] += x;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) c[i] = ts[i] = tc[i] = 0;
	
	vector<int> v;
	v.pb(0); // 改成base-1
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(!c[a[i]]) v.pb(a[i]); // 确保v里面数字不重复
		c[a[i]]++;
	}
	sort(v.begin(), v.end()); // 对不同数字按数值进行排序，确保从小到大处理，满足“支配数是最大值”的前提
	
	int ans = 1e9;
	for(int i = 1; i < v.size(); i++)
	{
		int cc = c[v[i]]; // 当前支配数的频次 cur_count
		int mx = cc - 1; // 其他数允许的最大频次
		
		int kp = querys(mx); // kp 初始化为频次 <= mx 的数字的总频次，keep-要保留的数字总数
		int kd = queryc(n) - queryc(mx);// 所有已加入的数字种类总数 - （频次 <= mx 的数字种类总数）
		kp += kd * mx;
		ans = min(ans, n - kp - cc); // 因为queryc(mx)把当前支配数也减去了，所以要加上cc
		
		updates(cc, cc);
		updatec(cc, 1);
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
// 8
// 1 2 3 2 4 4 3 3
// 4
// 1 2 3 4

// 2
// 3