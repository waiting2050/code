// 找到目标节点以后，其实一共就三种情况
// 1. 目标节点没有子节点，直接删除即可
// 2. 目标节点只有一个子节点，用子节点替换目标节点
// 3. 目标节点有两个子节点，用后继节点替换目标节点。麻烦在于找到后继节点，找到以后，依照样例1的图，采取用右子树最小节点取代
// 目标节点，再递归删除右子树最小节点的方案。
// 注意：后继节点一定没有左子树，但可能有右子树。删除时，需将其右子树挂载到其父节点的左侧。

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
    if root == nil {
        return nil
    }

    if root.Val > key {
        root.Left = deleteNode(root.Left, key)
    } else if root.Val < key {
        root.Right = deleteNode(root.Right, key)
    } else {
        if root.Left == nil {
            return root.Right
        }
        if root.Right == nil {
            return root.Left
        }

        scs := root.Right
        for scs.Left != nil {
            scs = scs.Left
        }
        root.Val = scs.Val
        root.Right = deleteNode(root.Right, scs.Val)
    }

    return root
}

// 示例 1:
// 输入：root = [5,3,6,2,4,null,7], key = 3
// 输出：[5,4,6,2,null,null,7]
// 解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
// 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
// 另一个正确答案是 [5,2,6,null,4,null,7]。


// 示例 2:
// 输入: root = [5,3,6,2,4,null,7], key = 0
// 输出: [5,3,6,2,4,null,7]
// 解释: 二叉树不包含值为 0 的节点


// 示例 3:
// 输入: root = [], key = 0
// 输出: []