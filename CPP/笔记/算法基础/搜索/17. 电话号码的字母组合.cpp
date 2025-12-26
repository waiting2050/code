// 全排列型dfs

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string t(n, 0);
        auto dfs = [&](this auto&& dfs, int dep) -> void
        {
            if(dep == n)
            {
                ans.push_back(t);
                return;
            }

            for(auto& c : mp[digits[dep] - '0'])
            {
                t[dep] = c;
                dfs(dep + 1);
            }
        };

        dfs(0);

        return ans;
    }
};

// 示例 1：
// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]


// 示例 2：
// 输入：digits = "2"
// 输出：["a","b","c"]