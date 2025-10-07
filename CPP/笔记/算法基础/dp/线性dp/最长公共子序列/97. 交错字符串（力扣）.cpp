class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        if (n + m ^ s3.size())
            return false;
        vector dp(n + 7, vector<bool>(m + 7)); // dp[i][j] 表示s1的前i个字符和s2的前j个字符是否能构成s3的前i+j个字符。

        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
        for (int j = 0; j < m; j++)
            dp[0][j + 1] = dp[0][j] && s2[j] == s3[j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = dp[i][j + 1] && s1[i] == s3[i + j + 1] ||
                                   dp[i + 1][j] && s2[j] == s3[i + j + 1];
            }
        }

        return dp[n][m];
    }
};

//示例 1：
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出：true


// 示例 2：
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出：false


// 示例 3：
// 输入：s1 = "", s2 = "", s3 = ""
// 输出：true