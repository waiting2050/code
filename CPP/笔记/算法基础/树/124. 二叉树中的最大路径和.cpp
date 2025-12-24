// 本题与437. 路径总和III的区别在于本题更类似求树的直径，利用贪心的性质；而路径总和III是用哈希表存前缀和，路径是直的，从根出发
// 到某个节点结束，不会从子节点到父节点再到子节点。

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
    int ans = INT_MIN;
public:
    int dfs(TreeNode* root)
    {
        if(!root) return 0;

        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));
        int x = root->val;

        ans = max(ans, x + l + r);

        return x + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// 示例 1：
// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6


// 示例 2：
// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42