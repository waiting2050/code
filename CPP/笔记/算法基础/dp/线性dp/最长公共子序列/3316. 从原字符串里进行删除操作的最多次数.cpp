class Solution
{
public:
    int maxRemovals(string source, string pattern, vector<int> &targetIndices)
    {
        int n = source.size(), m = pattern.size();
        unordered_set<int> st(targetIndices.begin(), targetIndices.end());
        vector dp(n + 7, vector<int>(m + 7)); // dp[i]][j]表示让source的前i位与pattern的前j位匹配的最多删除次数

        for (int j = 1; j <= m; j++) dp[0][j] = -2e9;
        for (int i = 0; i < n; i++)
        {
            int flag = st.count(i);
            dp[i + 1][0] = dp[i][0] + flag;
            for (int j = 0; j < m; j++) //其实与普通的删或不删是一样的，特别之处在于只有要删的数在
            {                           // targetIndices时才计数
                if (source[i] == pattern[j])
                    dp[i + 1][j + 1] = max(dp[i][j], dp[i][j + 1] + flag);
                else
                    dp[i + 1][j + 1] = dp[i][j + 1] + flag;
            }
        }

        return dp[n][m]; //怎么确保至少有一种匹配成功的方案？注意dp的初始化，当选择直接继承上方的时候，dp是很小的
                         // 所以一定是优先从左上角转移，也就是优先选择
    }
};

// 示例 1：
// 输入：source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
// 输出：1
// 解释：
// 不能删除 source[0] ，但我们可以执行以下两个操作之一：
// 删除 source[1] ，source 变为 "a_baa" 。
// 删除 source[2] ，source 变为 "ab_aa" 。


// 示例 2：
// 输入：source = "bcda", pattern = "d", targetIndices = [0,3]
// 输出：2
// 解释：
// 进行两次操作，删除 source[0] 和 source[3] 。


// 示例 3：
// 输入：source = "dda", pattern = "dda", targetIndices = [0,1,2]
// 输出：0
// 解释：
// 不能在 source 中删除任何字符。


// 示例 4：
// 输入：source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
// 输出：2
// 解释：
// 进行两次操作，删除 source[2] 和 source[3] 。