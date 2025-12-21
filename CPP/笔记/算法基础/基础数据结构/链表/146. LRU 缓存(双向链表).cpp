// 思路与库函数版本相同，但是将队列改成双向链表，哈希表依旧存地址，但是存节点指针

struct Node
{
    int key, val;
    Node* pre;
    Node* next;
};

class LRUCache {
private:
    int cap;
    Node* dummy;
    unordered_map<int, Node*> mp;

    void remove(Node* x)
    {
        x->pre->next = x->next;
        x->next->pre = x->pre;
    }

    void push_front(Node* x)
    {
        x->pre = dummy;
        x->next = dummy->next;
        dummy->next->pre = x;
        dummy->next = x;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        dummy = new Node;
        dummy->pre = dummy; // 注意哨兵节点创建以后前后指针都指向自己
        dummy->next = dummy;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        Node* x = it->second;
        remove(x);
        push_front(x);
        return x->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) 
        {
            auto x = it->second;
            x->val = value;
            remove(x);
            push_front(x);

            return;
        }

        Node* x = new Node;
        x->key = key, x->val = value;
        mp[key] = x;
        push_front(x);
        if(mp.size() > cap)
        {
            Node* back = dummy->pre;
            mp.erase(back->key);
            remove(back);
            delete back; // 别忘记释放内存
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */