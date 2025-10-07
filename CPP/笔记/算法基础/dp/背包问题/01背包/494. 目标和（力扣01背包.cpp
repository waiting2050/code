// 在和确定的情况下，加数部分与减数部分只要确定其一另一个也就确定了，经过数学运算可以知道加数=(sum + target) >> 1;
// 然后就可以转化成01背包问题，在容量为min(加数，减数)时刚好求得加数/减数的方案数

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size(), sum = 0;
        nums.resize(n + 7);
        for (int i = n - 1; i >= 0; i--)
            sum += nums[i], nums[i + 1] = nums[i];

        int nd = sum - target;
        if (sum < target || nd & 1)
            return 0;
        vector<int> dp((nd >> 1) + 7, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = nd >> 1; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];

        return dp[nd >> 1];
    }
};

//输入：nums = [ 1, 1, 1, 1, 1 ], target = 3
// 输出：5
// 解释：一共有 5 种方法让最终目标和为 3 。 -
// - 1 + 1 + 1 + 1 + 1 = 3
// + 1 - 1 + 1 + 1 + 1 = 3
// + 1 + 1 - 1 + 1 + 1 = 3
// + 1 + 1 + 1 - 1 + 1 = 3
// + 1 + 1 + 1 + 1 - 1 = 3

// 输入：nums = [1], target = 1
// 输出：1