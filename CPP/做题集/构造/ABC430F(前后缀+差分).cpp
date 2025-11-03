// 第i个数在哪只跟第i-1个数有关系;而i-1个数在哪跟i-2有关。对于RR=[i-2,i-1]，那么i-1在i-2右边，那么i-1左边起码得有1个空，i在i-1右边，
// 说明i-1左边起码一个空，i左边起码两个空。也就是说，i只能放在[3,n](base-1)，继续枚举RRR,RRRR发现某个数左边有多少连续的R，左边就有多少个空确定了
// 而如果是RRRLR中间的L就会破坏这种连续的确定关系。同理，对LLLL，会确定右边有多少确定的数。
// 假设RRRRRRR，第四个R代表左边至少4个空，右边至少3个空，那么第四个R所代表的数可以放在[5,n-3]，那么这个范围的数组可以放的可能性都+1，这个用差分维护

// Problem: AT ABC430 F
// Contest: AtCoder - AtCoder Beginner Contest 430
// URL: https://atcoder.jp/contests/abc430/tasks/abc430_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 3e5 + 7;

int lp[N], rp[N], ls[N], rs[N], d[N];

void solve()
{
	int n; cin >> n;
	for(int i = 0; i <= n; i++) lp[i] = rp[i] = ls[i] = rs[i] = d[i] = 0;
	string s; cin >> s;
	s = "?" + s;
	
	for(int i = 1; i < n; i++)
	{
		if(s[i] == 'L') lp[i] = lp[i - 1] + 1;
		if(s[i] == 'R') rp[i] = rp[i - 1] + 1;
	}
	for(int i = n - 1; i >= 1; i--)
	{
		if(s[i] == 'L') ls[i] = ls[i + 1] + 1;
		if(s[i] == 'R') rs[i] = rs[i + 1] + 1;
	}
	
	for(int i = 0; i < n; i++)
	{
		int l = rp[i] + ls[i + 1];
		int r = n - 1 - lp[i] - rs[i + 1];
		
		d[l]++, d[r + 1]--;
	}
	
	for(int i = 0; i < n; i++) 
	{
		d[i] += d[i - 1];
		cout << d[i] << " \n"[i + 1 == n];
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 5
// 5
// RLLR
// 3
// RL
// 2
// L
// 3
// RR
// 20
// RLLLLLLLLRLRRLLLRLR

// 2 4 3 4 2
// 2 2 1
// 1 1
// 1 1 1
// 5 9 13 14 15 17 18 19 19 20 20 19 19 18 17 16 14 12 9 5