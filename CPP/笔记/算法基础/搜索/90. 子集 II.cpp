// 与子集不同的是，这里的 nums 中可能包含重复元素。
// 为了避免重复，我们需要在搜索时，跳过所有与上一个元素相同且上一个元素未选的元素。
// 比如[2,2]，可以是[[], [2], [2, 2]]。为什么可能重复：假如第一个2选，第二个不选；与第一个不选，第二个选其实是一样的。
// 对于这种情况，我们规定：对于一排相同的数字，我们必须从左到右连续地选。如果前面的没选，后面的也不能选。

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        auto dfs = [&](this auto&& dfs, int dep) -> void
        {
            if(dep == n)
            {
                ans.push_back(t);
                return;
            }

            t.push_back(nums[dep]);
            dfs(dep + 1);
            t.pop_back();

            dep++;
            while(dep < n && nums[dep - 1] == nums[dep]) dep++;

            dfs(dep);
        };

        dfs(0);

        return ans;
    }
};

// 示例 1：
// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]


// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]