// Problem: Luogu P2642
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2642
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 7;

ll a[N], ldp[N], rdp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	rdp[n] = a[n], ldp[1] = a[1];
	for(int i = 2; i <= n; i++) ldp[i] = max(ldp[i - 1], 0ll) + a[i]; //这里求的是以i结尾的最大字段和 
	for(int i = 2; i <= n; i++) ldp[i] = max(ldp[i - 1], ldp[i]); //这里求的是前i位最大子段和，并不一定以i结尾 

	for(int i = n - 1; i; i--) rdp[i] = max(rdp[i + 1], 0ll) + a[i];
	for(int i = n - 1; i; i--) rdp[i] = max(rdp[i + 1], rdp[i]);
	
	ll ans = ldp[1] + rdp[3];
	for(int i = 3; i <= n - 1; i++) ans = max(ans, ldp[i - 1] + rdp[i + 1]);
	
	cout << ans;
	
	return 0;
}

//5
//83 223 -13 1331 -935
//
//1637
//
//
//3
//83 223 -13
//
//70
