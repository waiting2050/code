// Problem: Luogu P1833
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1833
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;

int dp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	char ch;
	int h1, m1, h2, m2, n; cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
	//cout << h1 << ' ' << m1 << ' ' << h2 << ' ' << m2 << ' ' << n;
	int dif = h2 * 60 + m2 - h1 * 60 - m1;
	
	for(int i = 1; i <= n; i++)
	{
		int t, c, p; cin >> t >> c >> p;
		
		if(!p)//如果是完全背包 
			for(int j = t; j <= dif; j++)
				dp[j] = max(dp[j], dp[j - t] + c);
		else//否则是多重背包（01背包也被包含在内） 
		{
			int x = 1; vector<int> v;
			while(p >= x) v.push_back(x), p -= x, x <<= 1;
			if(p) v.push_back(p);
			
			for(auto& y : v)
				for(int j = dif; j >= y * t; j--)
					dp[j] = max(dp[j], dp[j - y * t] + c * y);
		}
	}
	
	cout << dp[dif];
	
	return 0;
}

//6:50 7:00 3
//2 1 0
//3 3 1
//4 5 4
//
//11
