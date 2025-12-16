// 需要四个指针去模拟交换

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* n0 = new ListNode(0, head);
        ListNode* nhead = n0;
        ListNode* n1 = head;
        while(n1 && n1->next)
        {
            ListNode* n2 = n1->next;
            ListNode* n3 = n2->next;
            n0->next = n2;
            n2->next = n1;
            n1->next = n3;
            n0 = n1;
            n1 = n3;
        }

        return nhead->next;
    }
};

// 示例 1：
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]


// 示例 2：
// 输入：head = []
// 输出：[]


// 示例 3：
// 输入：head = [1]
// 输出：[1]