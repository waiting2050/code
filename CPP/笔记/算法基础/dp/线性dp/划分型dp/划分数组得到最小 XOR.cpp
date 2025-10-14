const int INF = 0x7f7f7f7f;

class Solution 
{
public:
    int minXor(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector dp(n + 7, vector<int> (k + 7, INF));

        vector<int> pre(n + 7);
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] ^ nums[i];

        dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= min(i, k); j++)
            {
                // if(j == 1) dp[i][j] = pre[i]; // 有的时候可能需要特判，当j==1，前i个必须选择，
                // else                          // 但实力else里的循环可能会漏前面的某些元素
                // {
                    for(int t = j - 1; t < i; t++)
                    {
                        dp[i][j] = min(dp[i][j], max(dp[t][j - 1] , (pre[i] ^ pre[t])));
                    }
                // }
            }
        }

        return dp[n][k];
    }
};

// 示例 1：
// 输入： nums = [1,2,3], k = 2
// 输出： 1
// 解释：
// 最优划分是 [1] 和 [2, 3]。
// 第一个子数组的 XOR 是 1。
// 第二个子数组的 XOR 是 2 XOR 3 = 1。
// 子数组中最大的 XOR 是 1，是最小可能值。


// 示例 2：
// 输入： nums = [2,3,3,2], k = 3
// 输出： 2
// 解释：
// 最优划分是 [2]、[3, 3] 和 [2]。
// 第一个子数组的 XOR 是 2。
// 第二个子数组的 XOR 是 3 XOR 3 = 0。
// 第三个子数组的 XOR 是 2。
// 子数组中最大的 XOR 是 2，是最小可能值。


// 示例 3：
// 输入： nums = [1,1,2,3,1], k = 2
// 输出： 0
// 解释：
// 最优划分是 [1, 1] 和 [2, 3, 1]。
// 第一个子数组的 XOR 是 1 XOR 1 = 0。
// 第二个子数组的 XOR 是 2 XOR 3 XOR 1 = 0。
// 子数组中最大的 XOR 是 0，是最小可能值。