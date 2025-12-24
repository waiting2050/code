// 题目要求的是某条路径的和，意味着路径以外的其余点都是干扰因素。本题选择自顶向下，以根节点为起点，向下遍历，记录路径上
// 的节点总和，然后用当前总和减去目标值，看是否存在之前记录的路径总和等于该值的情况。如果存在，说明当前路径上存在和为目标值的路径。
// 相当于枚举起点，然后用哈希表O(1)的去查终点

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
    int target;
    int ans;
    unordered_map<long long, int> mp;
public:
    void getcnt(TreeNode* root, long long sum)
    {
        if(!root) return;

        sum += root->val;

        long long nd = sum - target;
        if(mp.count(nd)) ans += mp[nd];
        
        mp[sum]++;
        getcnt(root->left, sum);
        getcnt(root->right, sum);
        mp[sum]--; // 记得恢复现场，因为路径以外的节点值都是干扰因素
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        mp[0]++;
        getcnt(root, 0);

        return ans;
    }
};

// 示例 1：

// 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// 输出：3
// 解释：和等于 8 的路径有 3 条，如图所示。


// 示例 2：
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：3