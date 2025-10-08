class Solution 
{
public:
    int minCut(string s) 
    {
        int n = s.size();
        s = "?" + s;
        s.resize(2 * n + 7);
        vector<int> dp(n + 7, 0x3f3f3f3f);
        vector<int> p(2 * n + 7);

        for(int i = 2 * n + 1; i >= 1; i--)
        {
            if(i & 1) s[i] = '#';
            else s[i] = s[i >> 1];
        }
        s[0] = '&', s[2 * n + 2] = '^';

        int C = 0, R = 0;
        for(int i = 1; i <= 2 * n + 1; i++)
        {
            p[i] = i < R ? min(p[2 * C - i], R - i) : 1;
            while(s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > R) C = i, R = i + p[i];
        }

        auto check = [&](int l, int r) -> bool
        {
            return p[l + r] >= r - l + 1;
        };

        for(int i = 1; i <= n; i++)
        {
            if(check(1, i)) 
            {
                dp[i] = 0;
                continue;
            }

            for(int j = 1; j <= i; j++)
                if(check(j, i))
                    dp[i] = min(dp[i], dp[j - 1] + 1);
        }

        return dp[n];
    }
};