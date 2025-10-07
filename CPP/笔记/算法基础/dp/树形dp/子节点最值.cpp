#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7, inf = 2e9;
int dpmin[N], dpmax[N], ans[N], n, x;
vector<int> g[N];

void dfs(int y, int pre)
{
	//对叶子节点特判 
	if(!g[y].size())
	{
		dpmin[y] = dpmax[y] = ans[y] = x;
		return;
	}
	
	//对父节点处理 
	for(auto& ele : g[y])
	{
		dfs(ele, y);
		dpmin[y] = min(dpmin[y], dpmin[ele]);
		dpmax[y] = max(dpmax[y], dpmax[ele]);
	}	
	ans[y] = dpmin[y] + dpmax[y] + 1;
	dpmax[y] = ans[y];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> x;
	for(int i = 2; i <= n; i++)
	{
		int y; cin >> y;
		g[y].push_back(i);
	}
	
	for(int i = 1; i <= n; i++) dpmin[i] = inf;
	dfs(1, 0);
	
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	
	return 0;
}

//4 5
//1 2 2 
//
//17 11 5 5
