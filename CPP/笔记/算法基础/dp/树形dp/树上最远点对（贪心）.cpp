#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
vector<int> g[N];
int w[N], dp[N], ans;

void dfs(int x)
{	
	for(auto& y : g[x])
	{
		dfs(y);
		//���Ĵ��룺ansһ��Ҫ��dp[x]ǰ��ȷ��ǰ���dp[x]�����ŵģ�Ȼ��ö�ٺ��� 
		ans = max(ans, dp[x] + dp[y] + w[y]);
		dp[x] = max(dp[x], dp[y] + w[y]);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	for(int i = 2; i <= n ;i++)
	{
		int p; cin >> p >> w[i];
		g[p].push_back(i);
	}
	
	dfs(1);
	
	cout << ans;
	
	return 0;
}

// 6
// 1 2
// 1 5
// 2 13
// 3 2
// 1 16
// 
// 31
