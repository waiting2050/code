#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
vector<int> g[N];//一维存储父节点，二维存储子节点

bitset<N> vis;//记录是否走过

//void dfs(int x)
//{
//	if (vis[x]) return; //走过就回溯
//	vis[x] = true;
//
//	for (auto& y : g[x]) dfs(y);//对子节点遍历
//}
//dfs也可以这么修改
void dfs(int x)
{
	vis[x] = true;

	for (auto& y : g[x])
	{
		if (vis[y]) continue;//把判断放在循环里，如果走过就跳过当前子节点

		dfs(y);
	}
}

void solve()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		if (u ^ v)g[u].push_back(v);//如果u和v不相等，即不形成自环，就输入
	}

	dfs(1);//从根节点开始遍历
	
	for (int i = 1; i <= n; i++) if (vis[i]) cout << i << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5 3
//1 2
//2 4
//4 5
//
//1 2 4 5
