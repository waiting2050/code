// 392. 判断子序列

// 简单
// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

// 进阶：
// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

// 下面是进阶难度的代码。定义 nct[i][c]表示t中下标≥i的最近字母c的下标。如果c不存在，则规定nct[i][c]=n用n表示没找到。
func isSubsequence(s string, t string) bool {
    n := len(t)
    nxt := make([][26]int, n + 1)
    for i := 0; i < 26; i++ {
        nxt[n][i] = n
    }

    for i := n - 1; i >= 0; i-- {
        nxt[i] = nxt[i + 1]
        nxt[i][t[i] - 'a'] = i 
    }

    idx := -1
    for _, c := range s {
        idx = nxt[idx + 1][c - 'a']
        if idx == n {
            return false
        }
    }
    return true
}

// 示例 1：
// 输入：s = "abc", t = "ahbgdc"
// 输出：true


// 示例 2：
// 输入：s = "axc", t = "ahbgdc"
// 输出：false