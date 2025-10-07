// Problem: 
//     P2036 [COCI 2008/2009 #2] PERKET
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2036
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 17;
int n, ans = INT_MAX;
struct
{
	int a, b;	//a for aci, b for bit
}d[N];

void dfs(int dep, int sum_a, int sum_b)
{
	if(sum_a != 1 && sum_b != 0)
		ans = min(ans, abs(sum_a - sum_b));
	if(dep == n + 1)
	{
		return;
	}
	
	dfs(dep + 1, sum_a * d[dep].a, sum_b + d[dep].b);
	dfs(dep + 1, sum_a, sum_b);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> d[i].a >> d[i].b;
	
	dfs(1, 1, 0);
	
	cout << ans;
	
	return 0;
}

