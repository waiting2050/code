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
    int mx;

    int getd(TreeNode* root)
    {
        if(!root) return 0;

        int l = getd(root->left), r = getd(root->right);
        mx = max(l + r, mx);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getd(root);

        return mx;
    }
};

// 示例 1：
// 输入：root = [1,2,3,4,5]
// 输出：3
// 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。


// 示例 2：
// 输入：root = [1,2]
// 输出：1