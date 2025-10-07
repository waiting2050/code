// 115. 不同的子序列
// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
// 测试用例保证结果在 32 位有符号整数范围内。

    // 动态规划有「选或不选」和「枚举选哪个」两种基本思考方式。子序列相邻无关一般是「选或不选」，子序列相邻相关（例如 LIS 问题）
    // 一般是「枚举选哪个」。本题用到的是「选或不选」，或者说「删或不删」。

    class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector dp(n + 7, vector<unsigned>(m + 7)); //用unsigned防止运算过程中溢出

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; // 此时t是空串，根据定义，我们只有一种方法可以从s中得到空串，即删除s的所有字母。
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = dp[i][j + 1]; //t数组里的每一位是一定要选的，所以不从dp[i+1][j]转移
                if (s[i] == t[j]) dp[i + 1][j + 1] += dp[i][j]; //相等的话要加上选或不选两种可能
            }
        }

        return dp[n][m];
    }
};

// 示例 1：
// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// rabbbit
// rabbbit
// rabbbit


// 示例 2：
// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag