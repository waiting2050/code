// 若改成第k大，只需要反过来，先遍历右子树再遍历左子树即可

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
    int kthSmallest(TreeNode* root, int& k) { // 注意这个k是引用
        if(root == nullptr) return -1;

        int l = kthSmallest(root->left, k);
        if(l != -1) return l;
        if(--k == 0) return root->val;
        return kthSmallest(root->right, k);
    }
};

// 示例 1：
// 输入：root = [3,1,4,null,2], k = 1
// 输出：1


// 示例 2：
// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3