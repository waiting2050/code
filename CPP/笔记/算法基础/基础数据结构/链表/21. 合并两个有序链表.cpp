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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *n1 = list1, *n2 = list2, head, *t = &head;

        while(n1 && n2)
        {
            if(n1->val < n2->val) t->next = n1, n1 = n1->next;
            else t->next = n2, n2 = n2->next;

            t = t->next;
        }
        t->next = n1 ? n1 : n2;

        return head.next;
    }
};

// 示例 1：
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]


// 示例 2：
// 输入：l1 = [], l2 = []
// 输出：[]


// 示例 3：
// 输入：l1 = [], l2 = [0]
// 输出：[0]