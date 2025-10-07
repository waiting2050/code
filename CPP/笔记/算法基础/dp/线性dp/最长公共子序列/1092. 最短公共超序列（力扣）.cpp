// 先求lcs，那么最短公共超序列（scs）的长度肯定是两个串的长度减去lcs长度。然后再根据dp的信息反推路径。

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector dp(n + 7, vector<int>(m + 7));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = str1[i] == str2[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        string ans;
        int i = n, j = m;
        while (i && j)
        {
            if (str1[i - 1] == str2[j - 1])
                ans = str1[--i] + ans, j--;
            else if (dp[i - 1][j] > dp[i][j - 1])
                ans = str1[--i] + ans;
            else
                ans = str2[--j] + ans;
        }

        return str1.substr(0, i) + str2.substr(0, j) + ans;
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