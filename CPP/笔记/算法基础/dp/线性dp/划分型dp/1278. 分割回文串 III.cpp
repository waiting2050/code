// dp[i][j]表示从s[1,i]，划分j段最少需要更改的字符数

class Solution 
{
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.size();
        s = "?" + s;
        vector op(n + 7, vector<int> (n + 7));

        for(int i = n; i >= 1; i--)
            for(int j = i; j <= n; j++)
                op[i][j] = op[i + 1][j - 1] + (s[i] != s[j]);

        vector dp(n + 7, vector<int> (k + 7, 0x3f3f3f3f));
        for(int i = 1; i <= n; i++)
        {
            dp[i][1] = op[1][i];
            
            for(int j = 1; j < i; j++)
                for(int t = 1; t <= min(j, k - 1); t++)
                    dp[i][t + 1] = min(dp[i][t + 1], dp[j][t] + op[j + 1][i]);
        }

        return dp[n][k];
    }
};

// 示例 1：
// 输入：s = "abc", k = 2
// 输出：1
// 解释：你可以把字符串分割成 "ab" 和 "c"，并修改 "ab" 中的 1 个字符，将它变成回文串。


// 示例 2：
// 输入：s = "aabbc", k = 3
// 输出：0
// 解释：你可以把字符串分割成 "aa"、"bb" 和 "c"，它们都是回文串。


// 示例 3：
// 输入：s = "leetcode", k = 8
// 输出：0