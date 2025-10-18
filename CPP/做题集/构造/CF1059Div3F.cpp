// Problem: CF 2162 F
// Contest: Codeforces - Codeforces Round 1059 (Div. 3)
// URL: https://codeforces.com/contest/2162/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题有一个规律，当021放一起的时候，会发现 情况1.选0不选1->mex=1->Mmex=0。情况2.选1不选0->mex=0->Mmex=1
// 情况3.选012->mex>=3->Mmex=2，所以答案肯定是{0,1,2}中的一个。只要分别讨论答案为这三种的情况即可
// 1.答案为0，那么所有区间必须都有0，于是mex>0->Mmex=0
// 2.答案为1，但这时候不是所有的区间都有0,1，只有1也是可以的，反正答案为0的时候排除了mex=0的可能。
// 但这个时候若区间有0，那么必须有1，否则Mmex不可能为1。0要么在1左边一个或者右边一个，讨论两种情况即可，
// 这时，0不能作为右/左端点。区间长度为1时，其本身是左端点也是右端点，判断的逻辑也是成立的
// 3.剩下只有答案为2的可能了，随便填充021即可

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 3e3 + 7;

bool st[N], ed[N]; // st/ed记录某个下标是否作为左端点/右端点出现
int l[N], r[N], cov[N], ans[N], n; // cov记录某个下标被几个区间覆盖

void init() 
{
	for(int i = 1; i <= n; i++) ans[i] = -1;
	for(int i = 1; i <= n; i++) cov[i] = st[i] = ed[i] = 0;
}

void fillOut()
{
	bitset<N> vis;
	for(int i = 1; i <= n; i++) if(ans[i] != -1) vis[ans[i]] = 1;
	
	int idx = 0;
	for(int i = 1; i <= n; i++)
	{
		while(vis[idx]) idx++;
		if(ans[i] == -1) 
		{
			vis[idx] = 1;
			ans[i] = idx++;
		}
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

void solve()
{
	int m; cin >> n >> m;
	init();
	
	for(int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
		st[l[i]] = 1;
		ed[r[i]] = 1;
		for(int j = l[i]; j <= r[i]; j++) cov[j]++;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(cov[i] == m)
		{
			ans[i] = 0;
			fillOut();
			return;
		}
	}
	
	for(int i = 1; i < n; i++)
	{
		if(!ed[i])
		{
			ans[i] = 0;
			ans[i + 1] = 1;
			fillOut();
			return;
		}
		
		if(!st[i + 1])
		{
			ans[i] = 1;
			ans[i + 1] = 0;
			fillOut();
			return;
		}
	}
	
	ans[1] = 0;
	ans[2] = 2;
	ans[3] = 1;
	fillOut();
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 5
// 3 1
// 1 2
// 3 5
// 1 1
// 1 2
// 2 2
// 2 2
// 2 3
// 4 5
// 1 2
// 2 3
// 3 4
// 1 1
// 4 4
// 5 4
// 3 5
// 1 1
// 2 4
// 4 4
// 4 2
// 1 3
// 2 4
// 
// 2 0 1
// 2 1 0
// 0 2 1 3
// 2 0 1 3 4
// 3 1 0 2