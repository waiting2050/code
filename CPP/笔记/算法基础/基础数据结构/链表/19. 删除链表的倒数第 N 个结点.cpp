// 由于需要删除节点，我们需要找倒数第n个节点的前一个节点
// 修改：左端点在链表头部，右端点在正数第n+1个节点。向右移动尺子，当尺子右端点到达链表末尾时，左端点就在倒数第n+1个节点。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, head}; // 注意这个虚拟源点，一方面方便了删除头节点的情况
                                    // 另一方面，比如n=2，此时r-l+1=3，确保长度为n+1
        ListNode *l = &dummy, *r = &dummy;
        
        while(n--) r = r->next;
        while(r->next)
        {
            l = l->next;
            r = r->next;
        }
        ListNode *nxt = l->next;
        l->next = l->next->next;
        delete nxt;
        
        return dummy.next;
    }
};

// 示例 1：
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]


// 示例 2：
// 输入：head = [1], n = 1
// 输出：[]


// 示例 3：
// 输入：head = [1,2], n = 1
// 输出：[1]