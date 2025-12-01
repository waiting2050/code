//

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        s = "?" + s;
        vector dp(n + 7, vector<int> (n + 7));

        int ans = 0;
        for(int len = 1; len <= n; ++len)
        {
            for(int i = 1; i + len - 1 <= n; ++i)
            {
                int j = i + len - 1;
                
                if(i == j) 
                {
                    dp[i][j] = 1;
                    continue;
                }

                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if(i <= word1.size() && j > word1.size()) ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return ans;
    }
};

// 示例 1：
// 输入：word1 = "cacb", word2 = "cbba"
// 输出：5
// 解释：从 word1 中选出 "ab" ，从 word2 中选出 "cba" ，得到回文串 "abcba" 。


// 示例 2：
// 输入：word1 = "ab", word2 = "ab"
// 输出：3
// 解释：从 word1 中选出 "ab" ，从 word2 中选出 "a" ，得到回文串 "aba" 。


// 示例 3：
// 输入：word1 = "aa", word2 = "bb"
// 输出：0
// 解释：无法按题面所述方法构造回文串，所以返回 0 。