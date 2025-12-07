// 设头节点到入环口需要走α步。设环长为c。
// 设相遇的时候，慢指针走了b步，那么快指针走了2b步。
// 设快指针比慢指针多走了 k圈，即 2b－b = kc，得b = kc。
// 慢指针从入环口开始，在环中走了b一α=kc一α步到达相遇点。这说明从相遇点开始，再走α步，就恰好走到入环口了！
// 虽然不知道α是多少，但如果让头节点和慢指针同时走，恰好α步后二者必定相遇，且相遇点就在入环口。

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                while(slow != head)
                {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }

        return nullptr;
    }
};


// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。


// 示例 2：
// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。


// 示例 3：
// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。