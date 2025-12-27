// 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

// 因为所有的字符都要被分割，于是直接枚举终点，终点+1就是下一个字符串起点。从起点开始，枚举其终点，判断是否是回文串，不断递归
// 处理。其实就是排列型的dfs。

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> t;
        vector ispalin(n + 7, vector<bool> (n + 7, true));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                ispalin[i][j] = s[i] == s[j] && ispalin[i + 1][j - 1];
            }
        }

        auto dfs = [&](this auto&& dfs, int st) -> void
        {
            if(st == n)
            {
                ans.push_back(t);
                return;
            }

            for(int e = st; e < n; e++)
            {
                if(ispalin[st][e])
                {
                    t.push_back(s.substr(st, e - st + 1));
                    dfs(e + 1);
                    t.pop_back();   
                }
            }
        };

        dfs(0);

        return ans;
    }
};

// 示例 1：
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]


// 示例 2：
// 输入：s = "a"
// 输出：[["a"]]