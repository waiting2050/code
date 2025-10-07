// Problem: CF 2106 D
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//思路：假设没有插入花的设定，那么显然可以用贪心的想法，a从左往右，只要大于b就选择。但是有了插入操作，这个时候可以把将一朵 
//花插入a的操作看作从b中删除一朵花，在删除以后如果能贪心的选择m-1朵花，那么取删除的最小的那一朵花的值即可。但如果暴力的去写复杂度O(nm)
//这个时候用前缀后缀的思想做个优化，对每个ai，看他在不插入的情况下从左往右能匹配几朵花，再从右往左处理一次。
//处理完以后，a被分为前后两段（前段a对应前段b，后段也是），只要前段+后段==m-1，这时候再插入一个数就可以凑出m 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], b[N], pre[N], suf[N];

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	pre[0] = suf[n + 1] = 0;//多组数据需要初始化 
	for(int i = 1, j = 1; j <= m && i <= n; i++)
	{
		if(a[i] >= b[j]) pre[i] = j++;
		else pre[i] = pre[i - 1];
		if(pre[i] == m)
		{
			cout << 0 << '\n';
			return;
		}
	}

	for(int i = n, j = m; i >= 1 && j >= 1; i--)
	{
		if(a[i] >= b[j]) suf[i] = m - j-- + 1;
		else suf[i] = suf[i + 1];
	}
	
	int ans = 2e9;
	for(int i = 0; i <= n; i++)//注意这里i从0开始，因为suf是i+1，如果i=1第一个位置的后缀会被忽略
	//那么若b第一个数很大，a永远匹配不上，pre就始终为0，而从后往前suf可能在当前位置匹配到m-1的可能被忽略 
		if(pre[i] + suf[i + 1] == m - 1)
			ans = min(ans, b[pre[i] + 1]);
	
	cout << (ans == 2e9 ? -1 : ans) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//7
//9 5
//3 5 2 3 3 5 8 1 2
//4 6 2 4 6
//6 3
//1 2 6 8 2 1
//5 4 3
//5 3
//4 3 5 4 3
//7 4 5
//6 3
//8 4 2 1 2 5
//6 1 4
//5 5
//1 2 3 4 5
//5 4 3 2 1
//6 3
//1 2 3 4 5 6
//9 8 7
//5 5
//7 7 6 7 7
//7 7 7 7 7
//
//6
//3
//7
//0
//-1
//-1
//7
