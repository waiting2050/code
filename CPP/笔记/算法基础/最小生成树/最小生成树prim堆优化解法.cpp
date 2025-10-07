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
const ll inf = 4e18;    // 定义常量 inf，表示无穷大

ll d[N];       // d 存储intree里的点到外面各个点的距离
bitset<N> intree;       // bitset 记录哪些节点已经在生成树中

struct Edge
{
    ll x, w;  // x 是目标节点，w 是边的权重
    bool operator <(const Edge& u)const
    {
        return w > u.w;  // 优先队列按权重从小到大排序
    }
};
vector<Edge> g[N];  // 邻接表，存储图的边信息

void solve()
{
    int n, m; cin >> n >> m;  // 读取节点数 n 和边数 m

    memset(d, 0x3f, sizeof(d));  // 初始化距离数组 d，所有节点的初始距离为 inf

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // 读取边 (u, v) 和权重 w
        g[u].push_back({ v, w });  // 添加边 (u, v)
        g[v].push_back({ u, w });  // 添加边 (v, u)，因为图是无向的
    }

    ll ans = 0;  // 初始化最小生成树的总权重为 0

    priority_queue<Edge> pq;  // 优先队列，用于存储待处理的节点及其距离
    pq.push({ 1, 0 });  // 将起点节点 1 推入优先队列，初始距离为 0
    d[1] = 0;  // 起点节点 1 的初始距离为 0

    while (pq.size())
    {
        int x = pq.top().x;  // 获取优先队列顶部的节点
        pq.pop();  // 弹出优先队列顶部的节点

        if (intree[x]) continue;  // 如果节点 x 已经在生成树中，跳过
        intree[x] = true;  // 将节点 x 标记为已在生成树中

        ans += d[x];  // 将节点 x 的距离 d[x] 加入到最小生成树的总权重中
        d[x] = 0;  // 将节点 x 的距离设为 0（可选操作，不影响结果）

        for (auto& ed : g[x])
        {
            auto y = ed.x, w = ed.w;  // 获取相邻节点 y 和边的权重 w
            if (!intree[y] && w < d[y])
            {
                d[y] = w;  // 更新节点 y 的最小距离
                pq.push({ y, w });  // 将节点 y 推入优先队列
            }
        }
    }

    cout << ans << '\n';  // 输出最小生成树的总权重
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
