// 注意到题目图是联通的（看作无向图）。于是从0开始遍历，
// 如果我们顺着原始方向走（从 a 到 b），说明这条路是“背离”城市 0 的，需要反转，计数加 1。
// 如果我们逆着原始方向走（从 b 到 a），说明这条路本来就是指向城市 0 的方向，无需反转。
// 于是需要建一个邻接表，不仅存了边，还存了方向。这可以用结构体实现，或者在本代码以[2]int的形式实现。

func minReorder(n int, connections [][]int) (ans int) {
    g := make([][][2]int, n)
    for _, a := range connections {
        u, v := a[0], a[1]
        g[u] = append(g[u], [2]int{v, 1})
        g[v] = append(g[v], [2]int{u, 0})
    }

    var dfs func(x, pre int)
    dfs = func(x, pre int) {
        for _, e := range g[x] {
            if ed, v := e[0], e[1]; ed != pre {
                ans += v 
                dfs(ed, x)
            }
        }
    }
    dfs(0, -1)

    return 
}

// 示例 1：
// 输入：n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// 输出：3
// 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。


// 示例 2：
// 输入：n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// 输出：2
// 解释：更改以红色显示的路线的方向，使每个城市都可以到达城市 0 。


// 示例 3：
// 输入：n = 3, connections = [[1,0],[2,0]]
// 输出：0