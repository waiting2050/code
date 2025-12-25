// 代码包括思路都是参照01trie树实现，只是这里改成了26个字母

const int N = 2e3 + 7;

class Trie {
    struct T
    {
        int son[26];
        bool end; // end用于标记否是叶子节点
    }t[N << 5]; // 由于节点编号由idx动态分配，于是N个点最多每个26个儿子，最多需要N*26个节点
    int idx;    // 分配N<<5的节点空间相当于N*32绰绰有余 

public:
    Trie() {
        memset(t[0].son, 0, sizeof(t[0].son));
        t[0].end = false;
        idx = 0;
    }
    
    void insert(string word) {
        int o = 0;
        for(auto& c : word)
        {
            int u = c - 'a';
            if(!t[o].son[u])
            {
                t[o].son[u] = ++idx; // 动态开点，字母被分配到子节点
                memset(t[idx].son, 0, sizeof(t[idx].son)); // 子节点都才刚刚分配，那子节点的儿子肯定是置空的，因为子节点儿子的编号肯定大于子节点编号
                t[idx].end = false; // 将初始化放到insert中，确保用到的节点才初始化，降低时间复杂度
            }
            o = t[o].son[u];
        }
        t[o].end = true;
    }
    
    bool search(string word) {
        int o = 0;
        for(auto& c : word)
        {
            int u = c - 'a';
            if(!t[o].son[u]) return false;
            o = t[o].son[u];
        }
        return t[o].end;
    }
    
    bool startsWith(string prefix) {
        int o = 0;
        for(auto& c : prefix)
        {
            int u = c - 'a';
            if(!t[o].son[u]) return false;
            o = t[o].son[u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//  示例：
// 输入
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// 输出
// [null, null, true, false, true, null, true]
// 解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // 返回 True
// trie.search("app");     // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app");     // 返回 True