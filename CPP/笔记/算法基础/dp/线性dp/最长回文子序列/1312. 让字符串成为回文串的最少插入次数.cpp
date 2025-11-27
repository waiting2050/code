// 这道题与516区别不大，一个是求最长，一个求最少修改次数，可以选择先求最长，再用总长-最长即可得到最少修改次数；
// 或者直接求最少修改次数，状态转移方程与516类似，只要把条件语句内的语句交换修改一下即可。

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        s = "?" + s;
        vector dp(n + 7, vector<int> (n + 7));

        for(int i = n; i; i--)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[1][n];
    }
};

// 示例 1：
// 输入：s = "zzazz"
// 输出：0
// 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。


// 示例 2：
// 输入：s = "mbadm"
// 输出：2
// 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。


// 示例 3：
// 输入：s = "leetcode"
// 输出：5
// 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。