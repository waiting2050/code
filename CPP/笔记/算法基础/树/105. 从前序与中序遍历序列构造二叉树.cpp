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


// 逻辑与上机课写的后序+中序转前序一致，只是改成了链表。唯一需要注意的是：一旦确定了当前节点，往后递归时，就不能再牵扯当前节点
// 最坏时间复杂度O(n²)，当树退化为链时。

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;

        int idx = 0;
        while(preorder[0] != inorder[idx]) idx++;

        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> pre2(preorder.begin() + 1 + idx, preorder.end());
        vector<int> in1(inorder.begin(), inorder.begin() + idx);
        vector<int> in2(inorder.begin() + 1 + idx, inorder.end());

        return new TreeNode(preorder[0], buildTree(pre1, in1), buildTree(pre2, in2));
    }
};


class Solution {
    unordered_map<int, int> mp;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr)
    {
        if(prel == prer) return nullptr;

        int idx = mp[preorder[prel]]; // idx是当前节点在inorder的位置
        int sz = idx - inl; // sz是左子树的大小

        TreeNode* l = build(preorder, inorder, prel + 1, prel + 1 + sz, inl, idx);
        TreeNode* r = build(preorder, inorder, prel + 1 + sz, prer, idx + 1, inr);

        return new TreeNode(preorder[prel], l, r);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;

        return build(preorder, inorder, 0, n, 0, n);
    }
};

// 示例 1:
// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]


// 示例 2:
// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]