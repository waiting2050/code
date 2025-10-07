// 求方案数的时候不能用二进制拆分，比如2可以拆成1+1和一个2，但二进制拆分以后v数组里就只有1
// 代表这个1会重复被选择，方案就重复了

const int P = 1e9 + 7;

class Solution
{
public:
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        vector<long long> dp(target + 7);

        dp[0] = 1;
        for (int i = 0; i < types.size(); i++)
        {
            long long s = types[i][0];
            for (int j = target; j >= types[i][1]; j--)
            {
                for (int k = 1; k <= min(s, 1ll * j / types[i][1]); k++)
                    dp[j] = (dp[j] + dp[j - k * types[i][1]]) % P;
            }
        }

        return dp[target];
    }
};
