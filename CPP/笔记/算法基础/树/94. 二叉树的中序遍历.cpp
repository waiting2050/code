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
class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root)
    {
        if(!root) return;

        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) { 
        dfs(root);

        return ans;
    }
};

// 例 1：
// 输入：root = [1,null,2,3]
// 输出：[1,3,2]


// 示例 2：
// 输入：root = []
// 输出：[]


// 示例 3：
// 输入：root = [1]
// 输出：[1]