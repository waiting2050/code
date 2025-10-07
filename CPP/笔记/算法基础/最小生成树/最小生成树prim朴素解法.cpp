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

const int N = 1e3 + 9;  // 定义常量 N，表示最大节点数
const ll inf = 4e18;    // 定义常量 inf，表示无穷大

ll a[N][N], d[N];       // a 存储图的邻接矩阵，d 存储intree里的点到外面各个点的距离
bitset<N> intree;       // bitset 记录哪些节点已经在生成树中

void solve()
{
    int n, m; cin >> n >> m;  // 读取节点数 n 和边数 m

    memset(a, 0x3f, sizeof(a));  // 初始化邻接矩阵 a，所有边的初始距离为 inf
    memset(d, 0x3f, sizeof(d));  // 初始化距离数组 d，所有节点的初始距离为 inf

    for (int i = 1; i <= n; i++) a[i][i] = 0;  // 自环距离为 0

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // 读取边 (u, v) 和权重 w
        a[u][v] = min(a[u][v], w);  // 更新邻接矩阵 a，防止多重边
        a[v][u] = min(a[v][u], w);  // 无向图，双向更新
    }
    d[1] = 0;

    ll ans = 0;  // 初始化最小生成树的总权重为 0

    for (int i = 1; i <= n; i++)
    {
        int u = -1;  // u 是要找的点中离生成树最近的点
        for (int j = 1; j <= n; j++)
            if (!intree[j] && (u == -1 || d[j] < d[u])) u = j;  // 找到距离生成树最近的节点 u
		
		if(d[u] >= inf) break;
        ans += d[u];
        intree[u] = true;  // 将节点 u 加入生成树

        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], a[u][j]);  // 更新节点 j 的最短距离
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1; 
    while (t--) solve();

    return 0;
}

//5 7
//2 3 5
//5 3 4
//5 2 6
//1 2 1
//1 5 2
//4 5 3
//3 4 3
//
//9
