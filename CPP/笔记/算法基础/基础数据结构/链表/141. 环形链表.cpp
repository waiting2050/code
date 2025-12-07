// 使用快慢指针，fast每次走两步，slow每次走一步，那么他们的相对速度就是1，只要有环，他们一定会相遇
// 或者也可以用哈希表去记录每个节点是否被访问过

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true; // 注意这里要先移动一次再判断
        }
        return false;
    }
};

// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。


// 示例 2：
// 输入：head = [1,2], pos = 0
// 输出：true
// 解释：链表中有一个环，其尾部连接到第一个节点。


// 示例 3：
// 输入：head = [1], pos = -1
// 输出：false
// 解释：链表中没有环。