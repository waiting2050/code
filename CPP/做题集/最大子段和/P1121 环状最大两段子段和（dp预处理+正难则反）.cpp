// Problem: Luogu P1121
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1121
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//对于这个问题，由于分成了两个子序列，我们不妨就是枚举一下可能出现的情况：
//无非就这两种（0就表示选了这个数，+就表示不选这个数）：
//1.+++++0000+++++0000++++
//2.0000++++00000++++000000
//不如求一次最大再求一次最小，答案要么是max,要么是sum-mi，最后再特判一下全负和只有一个正数的情况 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int a[N], ldp[N], rdp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i<= n; i++) cin >> a[i];
	
	ldp[1] = a[1];
	for(int i = 2; i <= n; i++) ldp[i] = max(ldp[i - 1], 0) + a[i];
	for(int i = 2; i <= n; i++) ldp[i] = max(ldp[i - 1], ldp[i]);
	rdp[n] = a[n];
	for(int i = n - 1; i; i--) rdp[i] = max(rdp[i + 1], 0) + a[i];
	for(int i = n - 1; i; i--) rdp[i] = max(rdp[i + 1], rdp[i]);
	
	int mx = ldp[1] + rdp[2];
	for(int i = 1; i <= n - 1; i++) mx = max(mx, ldp[i] + rdp[i + 1]);
	
	ldp[1] = a[1];
	for(int i = 2; i <= n; i++) ldp[i] = min(ldp[i - 1], 0) + a[i];
	for(int i = 2; i <= n; i++) ldp[i] = min(ldp[i - 1], ldp[i]);
	rdp[n] = a[n];
	for(int i = n - 1; i; i--) rdp[i] = min(rdp[i + 1], 0) + a[i];
	for(int i = n - 1; i; i--) rdp[i] = min(rdp[i + 1], rdp[i]);
	
	int mi = ldp[1] + rdp[2], sum = 0, cnt = 0;
	for(int i = 1; i <= n - 1; i++) mi = min(mi, ldp[i] + rdp[i + 1]);
	for(int i = 1; i <= n; i++)
	{
		sum += a[i];
		if(a[i] > 0) cnt++;
	}
	
	int ans = mx;
	if(mi != sum && sum - mi > mx && cnt > 1) ans = sum - mi;
	cout << ans;
	
	return 0;
}

// 3
// -1 1 -1
// 
// 0
// 
// 
// 3 
// -1 -1 -1
// 
// -2
// 
// 
// 7
// 2 -4 3 -1 2 -4 3
// 
// 9
