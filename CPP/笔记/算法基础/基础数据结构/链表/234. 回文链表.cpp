// 本题思路是链表几种操作的拼接，先找到链表的中间节点，然后将中间节点后面的链表反转，最后将前半部分链表和后半部分链表进行比较即可

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *getmid(ListNode* head) // 找到链表的中间节点
    {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) // 反转链表
    {
        ListNode *pre = nullptr, *cur = head;
        while(cur)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur, cur = nxt;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) { // 判断链表是否为回文链表
        ListNode* mid = getmid(head);
        ListNode* rvh = reverseList(mid), *h = head;

        while(rvh)
        {
            if(rvh->val != h->val) return false;
            rvh = rvh->next, h = h->next;
        }

        return true;
    }
};


// 示例 1：
// 输入：head = [1,2,2,1]
// 输出：true


// 示例 2：
// 输入：head = [1,2]
// 输出：false