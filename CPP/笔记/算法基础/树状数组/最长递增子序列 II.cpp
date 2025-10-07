// 对于本题，由于有一个差值不超过k的约束，用线段树更好处理。
// 具体来说，定义f[i][j]表示nums的前个元素中，以元素j（注意不是nums[j]）结尾的满足题目两个条件的子序列的最长长
// 度。
// 当j≠ nums[i] 时， f[i][j] =f[i-1][j]。
// 当 j= nums[j] 时，我们可以从 f[i-1][j'] 转移过来，这里 j-k≤ j′<j，取最大值
// 上式有一个「区间求最大值」的过程，这非常适合用线段树计算，且由于f[i]只会从f[i-1]转移过来，我们可以把f的第一个维
// 度优化掉。这样我们可以用线段树表示整个f数组，在上面查询和更新

const int N = 1e5 + 7, MX = 1e5;

class Solution 
{
    int t[N], dp[N];

public:
    int lowbit(int x) {return x & -x;}

    void update(int k, int x)
    {
        for(int i = k; i <= MX; i += lowbit(i)) t[i] = max(t[i], x);
    }

    int query(int l, int r)
    {
        int res = 0;
        while(l <= r)
        {
            res = max(res, dp[r]); //注意这里是dp而不是t数组。比方说输入nums = [1,5], k = 1
            r--;    //第一次t[1]t[2]t[4]...都会更新为1，此时在第二轮再用t[4]更新就会出错
                    //根本问题出在用区间的值更新了端点的值，所以在一步步走的时候得一步步更新，大步走时用区间更新
                    
            for(; r - lowbit(r) >= l; r -= lowbit(r)) res = max(res, t[r]);
        }

        return res;
    }

    int lengthOfLIS(vector<int>& nums, int k) 
    {
        int n = nums.size();

        for(auto& y : nums)
        {
            int x = query(max(y - k, 1), y - 1) + 1;
            update(y, x);
            dp[y] = max(dp[y], x);
        }

        return query(1, MX);
    }
};

// 示例 1：
// 输入：nums = [4,2,1,4,3,4,5,8,15], k = 3
// 输出：5
// 解释：
// 满足要求的最长子序列是 [1,3,4,5,8] 。
// 子序列长度为 5 ，所以我们返回 5 。
// 注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。


// 示例 2：
// 输入：nums = [7,4,5,1,8,12,4,7], k = 5
// 输出：4
// 解释：
// 满足要求的最长子序列是 [4,5,8,12] 。
// 子序列长度为 4 ，所以我们返回 4 。


// 示例 3：
// 输入：nums = [1,5], k = 1
// 输出：1
// 解释：
// 满足要求的最长子序列是 [1] 。
// 子序列长度为 1 ，所以我们返回 1 。