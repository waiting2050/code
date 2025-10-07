// 与10通配符匹配类似，区别在于对'*'的定义不同

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector dp(n + 7, vector<bool>(m + 7));

        dp[0][0] = 1;
        for (int j = 1; j <= m; j += 2) if (p[j] == '*') dp[0][j + 1] = dp[0][j - 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] | ((s[i] == p[j - 1] || p[j - 1] == '.') && dp[i][j + 1]);
                else if (p[j] == '.' || s[i] == p[j])
                    dp[i + 1][j + 1] = dp[i][j];
            }
        }

        return dp[n][m];
    }
};

// 示例 1：
// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。


// 示例 2:
// 输入：s = "aa", p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。


// 示例 3：
// 输入：s = "ab", p = ".*"
// 输出：true
// 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。