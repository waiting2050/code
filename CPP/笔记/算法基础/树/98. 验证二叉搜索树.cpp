// 中序遍历二叉搜索树是升序的

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
    bool isValidBST(TreeNode* root, long long l = LLONG_MIN, long long r = LLONG_MAX) {
         if(root == nullptr) return true;

        int x = root->val;
        return  l < x && x < r && isValidBST(root->left, l, x) && isValidBST(root->right, x, r);
    }
};

// 示例 1：
// 输入：root = [2,1,3]
// 输出：true


// 示例 2：
// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。