class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        s = "?" + s;
        vector dp(n + 7, vector<int> (n + 7));

        for(int i = 1; i <= n; i++) dp[i][i] = 1;
        for(int i = n; i >= 1; i--)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2; // 如果构成回文，长度+2
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 否则，从较长的区间继承，等同于删除右/左字符
            }
        }

        return dp[1][n];
    }
};

// 示例 1：
// 输入：s = "bbbab"
// 输出：4
// 解释：一个可能的最长回文子序列为 "bbbb" 。


// 示例 2：
// 输入：s = "cbbd"
// 输出：2
// 解释：一个可能的最长回文子序列为 "bb" 。