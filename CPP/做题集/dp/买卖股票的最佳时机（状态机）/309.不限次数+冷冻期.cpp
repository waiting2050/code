// 与不限次数的区别在于多了一个冷冻期，也就是卖了只能隔一天买回来，于是状态转移从前一天变成了前两天

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector dp(n + 7, vector<int> (2));

        dp[0][1] = -0x3f3f3f3f;
        dp[1][1] = -prices[0];
        for(int i = 0; i < n; i++)
        {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            // 注意卖了后明天当天买不了，要后天才行，于是dp[i-1][0],prices[i]下标不一样
            if(i >= 1) dp[i + 1][1] = max(dp[i][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n][0];
    }
};

// 示例 1:
// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]


// 示例 2:
// 输入: prices = [1]
// 输出: 0