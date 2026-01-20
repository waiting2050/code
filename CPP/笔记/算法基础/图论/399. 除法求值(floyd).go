// 将题目给的字符串数组先转成图，要求a/b的值，其实就是求点a->点b的路径长，考虑到数据范围，于是用floyd求路径长即可
// 难点在于怎么想到建图，以及怎么建图

func calcEquation(equations [][]string, values []float64, queries [][]string) (ans []float64) {
	// 因为floyd算法要在连续的整数上运行，所以要先将字符串映射到连续的整数（离散化）
    mp := map[string]int{}
    for _, a := range equations {
        if _, ok := mp[a[0]]; !ok {
            mp[a[0]] = len(mp)
        }
        if _, ok := mp[a[1]]; !ok {
            mp[a[1]] = len(mp)
        }
    }

	// 建图，初始化
    g := make([][]float64, len(mp))
    for i := range g {
        g[i] = make([]float64, len(mp))
    }
    for i, a := range equations {
        u, v := mp[a[0]], mp[a[1]]
        g[u][v] = values[i]
        g[v][u] = 1 / values[i]
    }

    for k := range g {
        for i := range g {
            for j := range g {
                g[i][j] = max(g[i][j], g[i][k] * g[k][j])
            }
        }
    }

    for i := range queries {
        u, oku := mp[queries[i][0]];
        v, okv := mp[queries[i][1]];
        if oku && okv && g[u][v] > 0 {
            ans = append(ans, g[u][v])
        } else {
            ans = append(ans, -1)
        }
    }

    return
}

// 示例 1：
// 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
// 解释：
// 条件：a / b = 2.0, b / c = 3.0
// 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 注意：x 是未定义的 => -1.0


// 示例 2：
// 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// 输出：[3.75000,0.40000,5.00000,0.20000]


// 示例 3：
// 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// 输出：[0.50000,2.00000,-1.00000,-1.00000]