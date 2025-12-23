// 题目要的是先序遍历的链表，如果直接先序遍历，那么右节点会被覆盖，需要引入额外的变量暂存它，逻辑会变得复杂。
// 但如果是后序遍历，这种方式是自底向上的，当你处理到根节点并修改 root->right = head 时，原本的右子树已经被处理完毕并保存在 head 中了，不存在丢失引用的风险。

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
    TreeNode* head;
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};

// 示例 1：
// 输入：root = [1,2,5,3,4,null,6]
// 输出：[1,null,2,null,3,null,4,null,5,null,6]


// 示例 2：
// 输入：root = []
// 输出：[]


// 示例 3：
// 输入：root = [0]
// 输出：[0]