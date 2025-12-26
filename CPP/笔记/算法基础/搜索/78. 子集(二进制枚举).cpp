class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < (1 << n); i++)
        {
            vector<int> t;
            for(int j = 0; j < n; j++)
            {
                if((i >> j) & 1) t.push_back(nums[j]);
            }
            ans.push_back(t);
        }

        return ans;
    }
};

// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]