// 第一反应是将两个字串连接起来，再求516最长回文子序列，但是题目要求两种字串不能为空。只需要加一个限制，
// 依旧将两个字串拼接成s，令dp[i][j]为s[i...j]最长回文子序列，与普通的求最长回文子序列状态转移一致，
// 但是在更新ans时，只有满足了两个字串都有字符选择才更新。

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