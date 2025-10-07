#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;
ll dp[N];	// 动态规划表，用于存储每个容量下的最大价值

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m, n; // 分别代表背包的最大容量和物品的数量
	cin >> m >> n;
	
	// 遍历每一个物品
	for(int i = 1; i <= n; i++)
	{
		int s, w, v; // 分别代表当前物品的数量、价值和体积
		cin >> s >> w >> v;
		
		vector<ll> vec;
		ll x = 1;
		while(s >= x) vec.push_back(x), s -= x, x <<= 1;
		if(s) vec.push_back(s);
		for(auto &ele: vec)
			// 倒序遍历从背包的最大容量到当前物品的价值
			for(int j = m; j >= ele * v; j--)
				// 确保当前容量可以容纳该物品，并更新动态规划表
					dp[j] = max(dp[j], dp[j - ele * v] + ele * w); // 更新为放入该物品后的最大价值
  	}
  	
  	  	cout << dp[m];
  	
  	return 0;
}
