// 通过观察发现，只有根节点的逻辑是特殊的，其余只需要判断左子树根节点和右子树根节点是否相同即可。

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
    bool check(TreeNode* l, TreeNode* r)
    {
        if(!l || !r) return l == r;
        return l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

// 示例 1：
// 输入：root = [1,2,2,3,4,4,3]
// 输出：true


// 示例 2：
// 输入：root = [1,2,2,null,3,null,3]
// 输出：false