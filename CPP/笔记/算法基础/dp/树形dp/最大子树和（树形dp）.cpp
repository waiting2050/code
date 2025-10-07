#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 定义常量N为图中可能的最大节点数加一些额外空间
const int N = 1e5 + 7;

// dp[i] 表示以节点i为根的子树中的最大路径和
int dp[N];
// w[i] 表示第i个节点的权重
int w[N];
// g[i] 是邻接表，表示与节点i相连的所有节点
vector<int> g[N];

// 深度优先搜索函数，root是当前节点，pre是它的父节点
void dfs(int root, int pre) 
{
    // 初始化dp[root]为节点root自身的权重
    dp[root] = w[root];
    
    // 遍历所有与root相邻的节点ele
    for (auto &ele : g[root]) 
    {
        if (ele == pre) continue; // 如果ele是父节点，则跳过，避免重复遍历
        dfs(ele, root); // 递归遍历子节点
        
        // 更新dp[root]，考虑加上子节点ele的dp值，但不一定要加，因为可能存在负权重
        dp[root] = max(dp[root], dp[root] + dp[ele]);
    }
}

// 解决单个测试用例的函数
void solve() {
    int n; cin >> n; // 输入节点数量n
    
    // 输入每个节点的权重
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    // 输入边信息，构建无向图
    for (int i = 1; i < n; i++) 
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 从节点1开始执行深度优先搜索,从2，3...开始也可以。父节点设置为-1，防止跳过（因为1为根，它没有父节点，所以用一个不可能会出现的点做父节点）
    dfs(1, -1);
    
    // 输出结果，即所有dp值中的最大值
    cout << *max_element(dp + 1, dp + n + 1) << '\n';
    
    // 清理全局变量，以便处理下一个测试用例
    for (int i = 1; i <= n; i++) 
    {
        dp[i] = w[i] = 0; 
        g[i].clear(); 
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// 1
// 5
// -5 -2 -3 10 10
// 1 2
// 1 3
// 3 4
// 3 5
// 
// 17
