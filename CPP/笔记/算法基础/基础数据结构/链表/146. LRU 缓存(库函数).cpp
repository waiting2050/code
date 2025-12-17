// 本题对时间复杂度要求严格，一开始容易想到用哈希表和队列去实现（不考虑链表），但是会发现对队列的更新是O(n)的，查找和更新
// 都是O(n)，有没有一种数据结构查找和更新是o(1)的呢？查找借助哈希表实现O(1)，更新可以借助链表实现O(1)。
// 只需要在哈希表中存链表节点地址，链表节点中存键值对，这样时间复杂度就合格了。接下来的难点在于链表操作的代码。
// 这里使用库函数list实现双向链表。

#define fi first
#define se second

class LRUCache {
public:
    int cap;
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto mit = mp.find(key); // mit此时是哈希表的迭代器
        if(mit == mp.end()) return -1;

        auto qit = mit->se; // qit哈希表的值，即链表的迭代器
        q.splice(q.begin(), q, qit); // splice函数是链表操作中常用的函数，将qit指向的节点移动到q的头节点

        return qit->se;
    }
    
    void put(int key, int value) {
        auto mit = mp.find(key);
        if(mit != mp.end())
        {
            auto qit = mit->se;
            qit->se = value;
            q.splice(q.begin(), q, qit);
            return;
        }

        q.push_front({key, value});
        mp[key] = q.begin();
        if(mp.size() > cap)
        {
            mp.erase(q.back().fi);
            q.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */