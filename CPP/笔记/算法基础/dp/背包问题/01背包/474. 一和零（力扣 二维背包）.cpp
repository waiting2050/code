class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector dp(m + 7, vector<int> (n + 7));

        for(int i = 0; i < strs.size(); i++)
        {
            int c0 = 0, c1 = 0;
            for(auto& y : strs[i])
            {
                if(y - '0') c1++;
                else c0++; 
            }

            for(int j = m; j >= c0; j--) //注意二维背包的更新
            {
                for(int k = n; k >= c1; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - c0][k - c1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};