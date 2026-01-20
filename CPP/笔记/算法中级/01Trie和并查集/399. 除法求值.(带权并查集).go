// 发现题目是有连通性与传递性的，且有相对关系（倍数关系），很自然想到带权并查集。
// 具体实现与模板代码差不多，只需要注意数值关系式的推导不要错（这种做法不离散化也行，但还是顺手离散化处理了）
// 如果按秩合并的话，注意数值关系式要分两种，因为merge(x,y)和merge(y,x)是不一样的

func calcEquation(equations [][]string, values []float64, queries [][]string) (ans []float64) {
    mp := map[string]int{}
    for i := range equations {
        u, v := equations[i][0], equations[i][1]
        if _, ok := mp[u]; !ok {
            mp[u] = len(mp)
        }
        if _, ok := mp[v]; !ok {
            mp[v] = len(mp)
        }
    }

    pre, d := make([]int, len(mp)), make([]float64, len(mp))
    for i := 0; i < len(mp); i++ {
        pre[i] = i
        d[i] = 1
    }
    
    var find func(x int) int
    find = func(x int) int {
        if pre[x] == x {
            return x
        }

        fa := pre[x]
        pre[x] = find(pre[x])
        d[x] *= d[fa]

        return pre[x]
    }

    merge := func(x, y int, val float64) {
        fx, fy := find(x), find(y)
        
        if fx == fy {
            return 
        }

        pre[fx] = pre[fy]
        d[fx] = val / d[x] * d[y]
    }

    for i := range equations {
        u, v := mp[equations[i][0]], mp[equations[i][1]]
        merge(u, v, values[i])
    }

    for i := range queries {
        u, oku := mp[queries[i][0]]
        v, okv := mp[queries[i][1]]

        if !oku || !okv {
            ans = append(ans, -1)
            continue
        }

        if find(u) != find(v) {
            ans = append(ans, -1)
        } else {
            ans = append(ans, d[u] / d[v])
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