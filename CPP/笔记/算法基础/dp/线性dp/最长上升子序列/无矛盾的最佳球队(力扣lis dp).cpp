//由于球员在数组中的下标不重要，所以可以按照分数或者年龄排序。这里按照分数从小到大排序，分数相同的按照年龄从小到大排序。
// 排序后，仿照最长递增子序列，定义 f[i]表示以 αges[i]结尾的递增子序列的最大得分，则有转移方程
// f[i] = max(f[j]) + scores[i]
// 其中 j<i且 ages[j] ≤ ages[i]。
// 初始 f[i] = 0。答案为 max(f[i])

const int N = 1e3 + 7, MX = 1e3;

class Solution 
{
    int t[N];

public:
    int lowbit(int x) {return x & -x;}

    void update(int k, int x)
    {
        for(int i = k; i <= MX; i += lowbit(i)) t[i] = max(t[i], x);
    }

    int query(int k)
    {
        int res = 0;
        for(int i = k; i; i -= lowbit(i)) res = max(res, t[i]);

        return res;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n = scores.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) v.push_back({scores[i], ages[i]});
        sort(v.begin(), v.end());

        for(auto& [s, age] : v) update(age, query(age) + s);

        return query(MX);
    }
};

// 示例 1：
// 输入：scores = [1,3,5,10,15], ages = [1,2,3,4,5]
// 输出：34
// 解释：你可以选中所有球员。


// 示例 2：
// 输入：scores = [4,5,6,5], ages = [2,1,2,1]
// 输出：16
// 解释：最佳的选择是后 3 名球员。注意，你可以选中多个同龄球员。


// 示例 3：
// 输入：scores = [1,2,3,5], ages = [8,9,10,1]
// 输出：6
// 解释：最佳的选择是前 3 名球员。