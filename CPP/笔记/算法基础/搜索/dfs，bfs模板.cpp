//代码模板——dfs 
//dfs有两种，一种是选或不选，另一种是全排列型 
type dfs(type x, ... ) // 可以存在多个变量
{
    if( ... ) // 达成目标，找到答案
    {
        ... // 输出答案或判断最优解等等
        return;
    }
    if( ... ) // 达到搜索边界（即到边界了还没搜到，有时没有此步骤）
    {
        return;
    }
    for( ... ) // 遍历所有子节点
    {
        if( ... ) // 可以转移状态，一般用标志变量判断
        {
            ... // 修改标志变量，表明此节点不可转移
            dfs( ... ) // 搜索子节点，经常为x+1
            ... // 还原标志变量，表明此节点可转移
        }
    }
}

//代码实现模板-bfs 
//等权最短路，最少操作次数 
bool vis[MAXN]; // 标记是否搜索过，有时也可直接用depth来判断
int depth[MAXN]; // 储存搜索深度，有时可能为二维数组或map
queue<type> que; // STL队列，不过数组模拟队列效率更高

type bfs(type start)
{
    que.push(start); // 起点入队
    depth[start] = 0; // 起点深度0
    vis[start] = true; // 标记起点
    while (!que.empty())
    {
        type now = que.front(); // 当前节点设置为队首
        que.pop(); // 弹出队首
        if ( ... ) // 如果达到目标条件
        {
            ans = depth[now]; // 储存答案
            return; // 搜索结束
        }
        for( ... ) // 遍历now节点的所有子节点，可用数组表示方向
        {
            type next = ... // 计算出子节点
            if (!vis[next] && ... ) // 如果子节点未搜索过，且范围符合题目条件
            {
                vis[next] = true; // 标记子节点
                depth[next] = depth[now] + 1; // 子节点深度+1
                que.push(next); // 子节点入队
                // 有时题目还需输出具体路径，可用一个数组储存每个节点的上一个节点，然后在此处对数组赋值。输出时，从结尾递归反向输出即可获得具体的路径。
            }
        }
    }
}
