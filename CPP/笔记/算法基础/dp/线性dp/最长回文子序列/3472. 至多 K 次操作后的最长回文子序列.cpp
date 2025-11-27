// 与516比起来多了一个替换的规则，并限制了替换的总次数，很自然想到要多增加一维k表示替换的次数，状态转移还是先从选或不选考虑
// 如果两字符相等，肯定选；如果不相等，要么不选，从dp[k][i + 1][j], dp[k][i][j - 1]转移，要么选，但是代价就是要花费与 两字符
// 在26个字母表中的差 相当的次数。

class Solution {
public:
    int longestPalindromicSubsequence(string s, int K) {
        int n = s.size();
        s = "?" + s;
        vector dp(K + 7, vector<vector<int>> (n + 7, vector<int> (n + 7)));

        int cnt = 0;
        for(int i = 1; i <= (n >> 1); i++) 
        {
            int dif = abs(s[i] - s[n - i + 1]);
            cnt += min(dif, 26 - dif);
        }
        if(cnt <= K) return n;

        for(int k = 0; k <= K; k++)
        {
            for(int i = n; i; i--)
            {
                dp[k][i][i] = 1;
                for(int j = i + 1; j <= n; j++)
                {
                    if(s[i] == s[j]) dp[k][i][j] = max(dp[k][i][j], dp[k][i + 1][j - 1] + 2);
                    else
                    {
                        dp[k][i][j] = max({dp[k][i][j], dp[k][i + 1][j], dp[k][i][j - 1]});

                        int dif = abs(s[i] - s[j]);
                        int op = min(dif, 26 - dif);
                        if(k >= op) dp[k][i][j] = max(dp[k][i][j], dp[k - op][i + 1][j - 1] + 2);
                    }
                }
            }
        }

        return dp[K][1][n];
    }
};

// 示例 1：
// 输入: s = "abced", k = 2
// 输出: 3
// 解释:
// 将 s[1] 替换为下一个字母，得到 "acced"。
// 将 s[4] 替换为上一个字母，得到 "accec"。
// 子序列 "ccc" 形成一个长度为 3 的回文，这是最长的回文子序列。


// 示例 2：
// 输入: s = "aaazzz", k = 4
// 输出: 6
// 解释:
// 将 s[0] 替换为上一个字母，得到 "zaazzz"。
// 将 s[4] 替换为下一个字母，得到 "zaazaz"。
// 将 s[3] 替换为下一个字母，得到 "zaaaaz"。
// 整个字符串形成一个长度为 6 的回文。