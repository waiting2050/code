// 先计算不插入字母时的 LCT 子序列个数，然后加上插入字母额外产生的 LCT 子序列个数。

// 不插入字母，问题lcs（一维字符子序列dp进阶版）

// 插入字母，分类讨论：

// 插入 L，插在 s 的最左边最优，额外产生的 LCT 子序列个数就是 s 中的 CT 子序列个数。lcs（一维字符子序列dp进阶版）代码即可。
// 插入 T，插在 s 的最右边最优，额外产生的 LCT 子序列个数就是 s 中的 LC 子序列个数。lcs（一维字符子序列dp进阶版）代码即可。
// 插入 C，我们枚举插在 s[i] 和 s[i+1] 之间，根据乘法原理，产生的额外 LCT 子序列个数，等于 s[0] 到 s[i] 中的 L 的个数，乘以 s[i+1] 到 s[n−1] 中的 T 的个数。取所有插入位置的最大值。
// 三种情况取最大值，即为插入字母所产生的额外 LCT 子序列个数。

using ll = long long;

const int N = 1e5 + 7;

ll dp[N][10];

class Solution
{
public:
    ll extraVal(string &s, const string &t)
    {
        int n = s.size(), m = t.size();

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if (s[i] == t[j])
                    dp[i + 1][j + 1] += dp[i][j];
            }
        }

        return dp[n][m];
    }

    ll extraMidVal(string &s)
    {
        int l = 0, t = 0;
        for (auto &y : s)
            if (y == 'T')
                t++;

        ll ans = 0;
        for (auto &y : s)
        {
            if (y == 'L')
                l++;
            else if (y == 'T')
                t--;
            ans = max(ans, 1ll * l * t);
        }

        return ans;
    }

    long long numOfSubsequences(string s)
    {
        ll extra = max({extraVal(s, string("CT")), extraVal(s, string("LC")), extraMidVal(s)});

        return extraVal(s, string("LCT")) + extra;
    }
};

// 示例 1：
// 输入： s = "LMCT"
// 输出： 2
// 解释：
// 可以在字符串 s 的开头插入一个 "L"，变为 "LLMCT"，其中包含 2 个子序列，分别位于下标 [0, 3, 4] 和 [1, 3, 4]。


// 示例 2：
// 输入： s = "LCCT"
// 输出： 4
// 解释：
// 可以在字符串 s 的开头插入一个 "L"，变为 "LLCCT"，其中包含 4 个子序列，
// 分别位于下标 [0, 2, 4]、[0, 3, 4]、[1, 2, 4] 和 [1, 3, 4]。


// 示例 3：
// 输入： s = "L"
// 输出： 0
// 解释：
// 插入一个字母无法获得子序列 "LCT"，结果为 0。