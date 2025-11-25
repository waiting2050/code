class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bitset<1007>> dp(n + 7); // dp[i][j]表示第i个数是否可以变成值为j

        bool all0 = true; // 特判一过来直接是合法的情况
        for(auto& y : nums) if(y) all0 = false;
        if(all0) return 0;

        for(int i = 0; i < n; i++) dp[i][nums[i]] = 1; // dp初始化

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];

            for(int j = l; j <= r; j++) dp[j] |= dp[j] >> v; // 用右移模拟减法

            int cnt = 0;
            for(int j = 0; j < n; j++) if(dp[j][0]) cnt++;
            if(cnt == n)
            {
                ans = i + 1;
                break;
            }
        }

        return ans ? ans : -1;
    }
};

// 示例 1：
// 输入： nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
// 输出： 2
// 解释：
// 对于查询 0 （l = 0, r = 2, val = 1）：
// 将下标 [0, 2] 的值减 1。
// 数组变为 [1, 0, 1]。
// 对于查询 1 （l = 0, r = 2, val = 1）：
// 将下标 [0, 2] 的值减 1。
// 数组变为 [0, 0, 0]，这就是一个零数组。因此，最小的 k 值为 2。


// 示例 2：
// 输入： nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
// 输出： -1
// 解释：
// 即使执行完所有查询，也无法使 nums 变为零数组。


// 示例 3：
// 输入： nums = [1,2,3,2,1], queries = [[0,1,1],[1,2,1],[2,3,2],[3,4,1],[4,4,1]]
// 输出： 4
// 解释：
// 对于查询 0 （l = 0, r = 1, val = 1）：
// 将下标 [0, 1] 的值减 1。
// 数组变为 [0, 1, 3, 2, 1]。
// 对于查询 1 （l = 1, r = 2, val = 1）：
// 将下标 [1, 2] 的值减 1。
// 数组变为 [0, 0, 2, 2, 1]。
// 对于查询 2 （l = 2, r = 3, val = 2）：
// 将下标 [2, 3] 的值减 2。
// 数组变为 [0, 0, 0, 0, 1]。
// 对于查询 3 （l = 3, r = 4, val = 1）：
// 将下标 4 的值减 1。
// 数组变为 [0, 0, 0, 0, 0]。因此，最小的 k 值为 4。


// 示例 4：
// 输入： nums = [1,2,3,2,6], queries = [[0,1,1],[0,2,1],[1,4,2],[4,4,4],[3,4,1],[4,4,5]]
// 输出： 4