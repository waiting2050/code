// Problem: CF 2094 E
// Contest: Codeforces - Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1.显然要拆位，预处理拆位，用一个桶去记录30个位里每个位有几个1（大小为30，因为最大到2^30）
//2.预处理以后，枚举每一个k，k在[1,n]，然后对ak的每一位去检查，
//如果当前位为1，异或以后把所有为0的位变成1，于是加上(当前位的位权*0的个数)； 反之，加上位权*1的个数 

const int N = 2e5 + 7;

int a[N];

void solve()
{
	vector<int>c(32, 0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 0; j < 30; j++)
		{
			int mask = a[i] >> j & 1;
			if(mask) c[j]++;
		}
	}
	
	// for(auto& y : c) cout << y << ' ';
	// cout << '\n';
	
	ll mx = 0;
	for(int i = 1; i <= n; i++)
	{
		ll ans = 0;
		for(int j = 0; j < 30; j++)
		{
			int mask = a[i] >> j & 1;
			ll k = 1 << j;
			//cout << k << ' ';
			ans += (mask ? k * (n - c[j]) : k * c[j]);
		}
		mx = max(mx, ans);
	}
	
	cout << mx << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//5
//3
//18 18 18
//5
//1 2 4 8 16
//5
//8 13 4 5 15
//6
//625 676 729 784 841 900
//1
//1
//
//0
//79
//37
//1555
//0
