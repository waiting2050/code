// 通过观察不难发现所谓的右视图就是每层最后节点，那么只需要层序遍历，取得每层最后节点即可。

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;

        q.push(root);
        while(q.size())
        {
            int n = q.size();
            vector<int> t;
            while(n--)
            {
                auto it = q.front(); q.pop();
                if(!n) ans.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        return ans;
    }
};

// 示例 1：
// 输入：root = [1,2,3,null,5,null,4]
// 输出：[1,3,4]


// 示例 2：
// 输入：root = [1,2,3,4,null,null,null,5]
// 输出：[1,3,4,5]


// 示例 3：
// 输入：root = [1,null,3]
// 输出：[1,3]


// 示例 4：
// 输入：root = []
// 输出：[]