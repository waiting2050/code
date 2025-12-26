class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        vector<vector<int>> ans;

        auto dfs = [&](this auto&& dfs, int dep) -> void
        {
            if(dep == n)
            {
                ans.push_back(t);
                return;
            }

            t.push_back(nums[dep]); // 选
            dfs(dep + 1);
            t.pop_back(); // 回溯，恢复现场

            dfs(dep + 1); // 不选
        };

        dfs(0);

        return ans;
    }
};

// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]