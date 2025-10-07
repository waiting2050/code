class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector dp(n + 7, vector<bool>(m + 7));

        if (p == "*") return true;

        dp[0][0] = 1;
        for (int j = 0; j < m; j++) if (p[j] == '*') dp[0][j + 1] = dp[0][j];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (p[j] == '*') dp[i + 1][j + 1] = dp[i + 1][j] | dp[i][j + 1]; //dp[i+1][j]相当于删除p[j]，即删除'*'
                // 可以看做是匹配空串。dp[i][j+1]即删除s[i]，也可以理解为'*'匹配上了所有删掉的字符。
                // 为什么不是从dp[i][j]转移？若从这转移表示s[i]与p[j]是一对一的关系，而非一对多
                else if (p[j] == '?' || s[i] == p[j]) dp[i + 1][j + 1] = dp[i][j];
            }
        }

        return dp[n][m];
    }
};

// 示例 1：
// 输入：s = "aa", p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。


// 示例 2：
// 输入：s = "aa", p = "*"
// 输出：true
// 解释：'*' 可以匹配任意字符串。


// 示例 3：
// 输入：s = "cb", p = "?a"
// 输出：false
// 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。