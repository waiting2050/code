// 用小根堆实现，难度在于自定义比较函数

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
    struct cmp
    {
        bool operator()(const ListNode* a, const ListNode* b) const
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto& y : lists) if(y) pq.push(y);

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(pq.size())
        {
            auto it = pq.top(); pq.pop();
            cur->next = it;
            if(it->next) pq.push(it->next);
            cur = cur->next;
        }

        return dummy->next;
    }
};