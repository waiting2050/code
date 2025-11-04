class Solution 
{
public:
    bool checkPartitioning(string s) 
    {
        int n = s.size();
        s = "?" + s;
        string cs = s;
        s.resize(2 * n + 7);
        vector<int> p(2 * n + 7);

        for(int i = 2 * n + 1; i >= 1; i--)
        {
            if(i & 1) s[i] = '#';
            else s[i] = s[i >> 1];
        }

        int C = 0, R = 0;
        for(int i = 1; i <= 2 * n + 1; i++)
        {
            p[i] = i < R ? min(p[2 * C - i], R - i) : 1;
            while(s[i + p[i]] == s[i - p[i]]) p[i]++;
            if(i + p[i] > R) C = i, R = i + p[i];
        }
        auto check = [&](int l, int r) -> bool 
        {
            return p[l + r] >= r - l + 1;
        };
        
        // 代码注释掉的部分是继承自1278分割回文串三的写法，但是这题只要枚举两个断点即可
        for(int i = 1; i <= n - 2; i++)
        {
            for(int j = i + 1; j <= n - 1; j++)
            {
                if(check(1, i) && check(i + 1, j) && check(j + 1, n)) return true;
            }
        }
        return false;
        // vector dp(n + 7, vector<bool> (10));
        // for(int i = 1; i <= n; i++)
        // {
        //     dp[i][1] = check(1, i);
        //     for(int j = 1; j < i; j++)
        //     {
        //         for(int t = 1; t <= min(2, j); t++)
        //         {
        //             dp[i][t + 1] = dp[i][t + 1] | (dp[j][t] & check(j + 1, i));
        //         }
        //     }
        // }
        // return dp[n][3];
    }
};

// 示例 1：
// 输入：s = "abcbdd"
// 输出：true
// 解释："abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。


// 示例 2：
// 输入：s = "bcbddxy"
// 输出：false
// 解释：s 没办法被分割成 3 个回文子字符串。