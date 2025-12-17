// 这个代码其实主要由两个链表代码组成，一个是找链表中间节点（需要简单修改，把中间节点的前一个节点断开）；另一个事是合并两个有序链表
// 跟归并排序模板是一个思路，找中点->分治->合并

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
    ListNode* getmid(ListNode* head)
    {
        ListNode* slow = head, *fast = head, *pre = head;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        return slow;
    }

    ListNode* mergeList(ListNode* h1, ListNode* h2)
    {
        ListNode head, *n1 = h1, *n2 = h2, *cur = &head;
        while(n1 && n2)
        {
            if(n1->val < n2->val) cur->next = n1, n1 = n1->next;
            else cur->next = n2, n2 = n2->next;
            
            cur = cur->next;
        }
        cur->next = n1 ? n1 : n2;

        return head.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getmid(head);
        ListNode* l = sortList(head);
        ListNode* r = sortList(mid);

        return mergeList(l, r);
    }
};