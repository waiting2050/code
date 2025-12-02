// 考虑这么一种情况，首先对于字符串bcb，它的回文子序列有四种情况b,c,bb,bcb，接下来分类讨论：
// 一、s[i]==s[j]
// 1、字符串两端的字符未出现过，比如aa，那么aa可以接到四种情况两边，而且a单独出现算一种，aa算一种dp[i][j]=dp[i + 1][j - 1]+2
// 2.字符串两端的字符出现过一次，比如cc，那么cc，依然能接四种情况，但是不能单独出现了，因为这个情况统计过了
// 3.字符串两段的字符出现过了两次及以上，那么bb，依然可以考虑接四种情况，但是此时不能有新增的b或bb了，
//   并且有重复的情况，比如本来就有bcb了，这个时候bb再接到c两端就重复了。于是找到里面管辖范围最大的bb
//   假设两个下标为l,r，扣除这一段[l+1,r-1]，就得到答案了
// 二、s[i]!=s[j]
// 那么直接继承，并且减去重复计算的情况，dp[i][j]=dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]

const int P = 1e9 + 7;

class Solution {
public:
    int countPalindromicSubsequences(string& s) {
        int n = s.size();
        s = "?" + s;
        vector dp(n + 7, vector<int> (n + 7));
        vector<int> last(7), l(n + 7), r(n + 7, n + 1);

        // 预处理出每个字符出现的位置
        for(int i = 1; i <= n; ++i)
        {
            int ch = s[i] - 'a';
            if(last[ch])
            {
                l[i] = last[ch];
                r[last[ch]] = i;
            }
            last[ch] = i;
        }

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
                    dp[i][j] = dp[i + 1][j - 1] << 1;
                    
                    if(l[j] < r[i]) dp[i][j] += 2;
                    else if(l[j] == r[i]) ++dp[i][j];
                    else dp[i][j] -= dp[r[i] + 1][l[j] - 1];
                }
                else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];

                dp[i][j] = (dp[i][j] % P + P) % P;
            }
        }

        return dp[1][n];
    }
};

// 示例 1：
// 输入：s = 'bccb'
// 输出：6
// 解释：6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
// 注意：'bcb' 虽然出现两次但仅计数一次。


// 示例 2：
// 输入：s = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
// 输出：104860361
// 解释：共有 3104860382 个不同的非空回文子序列，104860361 是对 109 + 7 取余后的值。