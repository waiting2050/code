// 这题主要难在确保 所有操作分数相同 的前提，所以要从最外层开始，提前拿到操作分数进行区间dp
// 怎么想到区间dp？因为模拟一下消除过程，发现由外向内缩小

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        auto del = [&] (int st, int ed, int target) -> int
        {
            vector dp(n + 7, vector<int> (n + 7));

            for(int len = 2; len <= n; ++len)
            {
                for(int i = 1; i + len - 1 <= n; ++i)
                {
                    int j = i + len - 1;

                    if(nums[i] + nums[j] == target) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                    if(nums[i] + nums[i + 1] == target) dp[i][j] = max(dp[i][j], dp[i + 2][j] + 1);
                    if(nums[j] + nums[j - 1] == target) dp[i][j] = max(dp[i][j], dp[i][j - 2] + 1);
                }
            }

            return dp[st][ed];
        };

        int r1 = del(3, n, nums[1] + nums[2]);
        int r2 = del(1, n - 2, nums[n - 1] + nums[n]);
        int r3 = del(2, n - 1, nums[1] + nums[n]);

        return max({r1, r2, r3}) + 1;
    }
};

// 示例 1：
// 输入：nums = [3,2,1,2,3,4]
// 输出：3
// 解释：我们执行以下操作：
// - 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,2,3,4] 。
// - 删除第一个元素和最后一个元素，分数为 1 + 4 = 5 ，nums = [2,3] 。
// - 删除第一个元素和最后一个元素，分数为 2 + 3 = 5 ，nums = [] 。
// 由于 nums 为空，我们无法继续进行任何操作。


// 示例 2：
// 输入：nums = [3,2,6,1,4]
// 输出：2
// 解释：我们执行以下操作：
// - 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
// - 删除最后两个元素，分数为 1 + 4 = 5 ，nums = [6] 。
// 至多进行 2 次操作。