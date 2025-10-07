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

const int N = 1e5 + 9;  // 定义常量 N，表示最大节点数

int pre[N];  // 并查集数组，用于记录每个节点的父节点

// 查找根节点，并进行路径压缩
int root(int x) {return pre[x] = (pre[x] == x ? x : root(pre[x])); }

// 边结构体，包含起点 u，终点 v 和权重 w
struct Edge
{
    ll u, v, w;
    bool operator <(const Edge& m)const
    {
        return w < m.w;  // 重载小于运算符，使边按权重从小到大排序
    }
};

void solve()
{
    int n, m; cin >> n >> m;  // 读取节点数 n 和边数 m

    vector<Edge> es;  // 存储所有的边

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // 读取边 (u, v) 和权重 w
        es.push_back({ u, v, w });  // 将边添加到边的集合中
    }

    sort(es.begin(), es.end());  // 按权重对边进行排序

    ll ans = 0;  // 初始化最小生成树的总权重为 0

    for (int i = 1; i <= n; i++) pre[i] = i;  // 初始化并查集，每个节点的父节点是自己

    for (auto& ele : es)
    {
        ll u = ele.u, v = ele.v, w = ele.w;  // 获取边的起点 u，终点 v 和权重 w

        if (root(u) == root(v)) continue;  // 如果 u 和 v 在同一个集合中，跳过这条边
        ans += w;  // 将边的权重 w 加入到最小生成树的总权重中
        pre[root(u)] = root(v);  // 合并 u 和 v 所在的集合
    }

    // 检查是否所有节点都在同一个连通分量中
    for (int i = 1; i < n; i++) if (root(i) != root(i + 1)) ans = -1;

    cout << ans << '\n';  // 输出最小生成树的总权重，如果无法生成最小生成树则输出 -1
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
