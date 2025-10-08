class Solution 
{
public:
    int minCut(string s) 
    {
        int n = s.size();
        s = "?" + s;
        vector ok(n + 7, vector<bool> (n + 7, true));
        vector dp(n + 7, 0x3f3f3f3f);
        
        //如何思考遍历顺序：观察状态转移方程，从ok[i+1][j-1]来，因此i必须倒序枚举
        for(int i = n; i >= 1; i--) // 而更新列时下一行的状态已经更新完毕，因此j正序或倒序都可以
            for(int j = i; j <= n; j++)
                ok[i][j] = s[i] == s[j] && ok[i + 1][j - 1];

        for(int i = 1; i <= n; i++)
        {
            if(ok[1][i]) // 初始化dp
            {
                dp[i] = 0;
                continue;
            }
            
            for(int j = 1; j <= i; j++)
                if(ok[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
        }

        return dp[n];
    }
};


//示例 1：
// 输入：s = "aab"
// 输出：1
// 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。


// 示例 2：
// 输入：s = "a"
// 输出：0


// 示例 3：
// 输入：s = "ab"
// 输出：1