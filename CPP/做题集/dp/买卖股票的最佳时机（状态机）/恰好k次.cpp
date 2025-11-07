class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector dp(n + 7, vector<vector<int>> (k + 7, vector<int> (2, -0x3f3f3f3f)));

        dp[0][1][0] = 0; // 与至多k次唯一的不同就是只有=1
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= k + 1; j++)
            {
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j][1] + prices[i]);
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i]);
            }
        }

        return dp[n][k + 1][0];
    }
};