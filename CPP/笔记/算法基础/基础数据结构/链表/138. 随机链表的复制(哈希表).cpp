// 这段代码使用哈希表来解决随机链表的深拷贝问题。算法分为两个步骤：
// 1.第一次遍历原始链表，创建每个节点的新副本，并将原节点与新节点的映射关系存储在哈希表中
// 2.第二次遍历原始链表，利用哈希表设置新链表中每个节点的next和random指针

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
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while(cur)
        {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur)
        {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return mp[head];
    }
};