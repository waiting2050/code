// 经典三指针，pre, cur, nxt，分别指向前一个节点，当前节点，下一个节点
// 每次循环将当前节点的next指针指向前一个节点，然后将pre, cur, nxt指针分别后移一位
// 直到cur指针为空，返回pre指针即可·

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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while(cur != nullptr)
        {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur, cur = nxt;
        }

        return pre;
    }
};

// 示例 1：
// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]


// 示例 2：
// 输入：head = [1,2]
// 输出：[2,1]


// 示例 3：
// 输入：head = []
// 输出：[]