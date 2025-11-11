// 与不限次数相比只多了一个手续费，只要在状态转移的时候处理手续费即可

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector dp(n + 7, vector<int> (2));

        dp[0][1] = -0x3f3f3f3f;
        for(int i = 0; i < n; i++)
        {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i] - fee);
        }

        return dp[n][0];
    }
};

// 示例 1：
// 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出：8
// 解释：能够达到的最大利润:  
// 在此处买入 prices[0] = 1
// 在此处卖出 prices[3] = 8
// 在此处买入 prices[4] = 4
// 在此处卖出 prices[5] = 9
// 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8


// 示例 2：
// 输入：prices = [1,3,7,5,10,3], fee = 3
// 输出：6