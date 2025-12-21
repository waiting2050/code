/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// dfs:
class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int dep)
    {
        if(!root) return;

        if(dep >= ans.size()) ans.push_back({root->val});
        else ans[dep].push_back(root->val);
        
        dfs(root->left, dep + 1), dfs(root->right, dep + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        return ans;
    }
};


// bfs:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        while(q.size())
        {
            int n = q.size();
            vector<int> t;
            while(n--)
            {
                auto it = q.front(); q.pop();
                t.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans.push_back(t);
        }

        return ans;
    }
};


// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]


// 示例 2：
// 输入：root = [1]
// 输出：[[1]]


// 示例 3：
// 输入：root = []
// 输出：[]