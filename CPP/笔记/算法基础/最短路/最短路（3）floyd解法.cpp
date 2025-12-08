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

const int N = 300 + 7;
const ll inf = 4e18;//0x3f3f3f3f3f3f3f3f(8个3f)约等于4.5e18,将inf设置为4e18已经足够大
int n, m, q;
ll d[N][N];//d[i][j]表示从i到j的距离
//floyd法，适用于500以下，负权时也成立，可以处理多源最短路问题 
void solve()
{
	cin >> n >> m >> q;
	memset(d, 0x3f, sizeof(d));//将每一个字节初始化为0x3f
	
	for (int i = 1; i <= m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;//因为可能重边，所以取最小的那一次
		d[u][v] = min(d[u][v], w);
	}

	for (int i = 1; i <= n; i++) d[i][i] = 0;//因为可能自环或者初始化d的0x3f未被修改导致答案错误（比如询问1 1距离应该是0， 但是输出-1的情况）

		for (int k = 1; k <= n; k++)//中间节点
			for (int i = 1; i <= n; i++)//入点
				for (int j = 1; j <= n; j++)//出点
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//模板，记忆

		while (q--)
		{
			int u, v; cin >> u >> v;
			cout << (d[u][v] >= inf ? -1 : d[u][v]) << '\n';
		}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//3 3 2
//1 2 5
//2 3 2
//1 3 10
//1 3
//3 1
//
//7
//- 1

