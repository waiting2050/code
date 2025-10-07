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

const int N = 60;
int fa[N];//父节点

vector<int> g[N];//graph,相当于二维数组g[][],第二个框放vector

void dfs(int x)
{
	cout << x << ' ';
	for (auto& y : g[x]) //遍历当前父节点的所有子节点
		dfs(y);//对每个子节点dfs
}

void bfs(int rt)
{
	queue<int> q;
	q.push(rt);//将根节点入队
	while (q.size())//当队列非空
	{
		int x = q.front(); q.pop();//取出队首
		cout << x << ' ';
		for (auto& y : g[x]) q.push(y);//将队首的所有子节点入列
	}
}//比如1是根，下面是2，3.那么会输出1，将2，3入队，再依次将2，3的子节点入队

void solve()
{
	int n; cin >> n;
	for (int i = 2; i <= n; i++) 
	{
		cin >> fa[i];
		g[fa[i]].push_back(i);//第一个框放父节点，第二个框放子节点
	}
	//i要从1开始，因为父节点从1开始
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());//对子节点进行排序

	dfs(1);//从第一个父节点开始
	cout << '\n';
	bfs(1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//4
//1 1 2
//
//1 2 4 3
//1 2 3 4
