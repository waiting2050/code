// 本质是链表反转，但是得有多个指针去记录不同的拆分后的链表，用虚拟的头结点防止特判。总共需要五个关键指针，
// pre为上一个链表尾，start为当前链表头，end为当前链表尾，aux为下一个链表头，t是辅助遍历的指针。

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur, cur = nxt;
        } 

        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while(1)
        {
            ListNode* t = pre;
            for(int i = 0; i < k; i++)
            {
                t = t->next;
                if(!t) return dummy->next;
            }

            ListNode* start = pre->next;
            ListNode* aux = t->next;

            t->next = nullptr;
            ListNode* end = reverseList(start);

            pre->next = end;
            start->next = aux;
            pre = start;
        }
    }
};