// 1→1′→2→2′→3→3′
// 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        // 构造链表副本，每个点接在原件后面
        Node* cur = head;
        while(cur)
        {
            Node* nxt = cur->next;
            Node* nn = new Node(cur->val);
            nn->next = cur->next;
            cur->next = nn;
            cur = nxt;
        }

        // 完成随机指针的复制
        cur = head;
        while(cur)
        {
            if(cur->random) cur->next->random = cur->random->next; // 最关键的一步
            cur = cur->next->next;
        }

        // 把交错的链表分开
        cur = head;
        Node* nhead = head->next;
        while(cur->next->next)
        {
            Node* curr = cur->next;
            cur->next = cur->next->next;
            curr->next = curr->next->next;
            cur = cur->next;
        }
        cur->next = nullptr; // 原来的链表尾指向了副本，因此它需要置空，而副本的链表尾初始化的时候默认为空

        return nhead;
    }
};