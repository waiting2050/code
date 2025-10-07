#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;  // 原始数组最大长度

int n;                  // 实际数组长度
ll a[N];                // 原始数组（1-based索引）
ll t[N << 2];           // 线段树节点数组（大小4*N，存储区间异或和）
ll lz[N << 2];          // 懒标记数组（存储待传递的异或值）

// 向上更新当前节点的值（由左右子节点的异或和合并）
void pushup(int o)
{
    // 当前节点的异或和 = 左子节点异或和 ^ 右子节点异或和
    t[o] = t[o << 1] ^ t[o << 1 | 1];
}

// 构建线段树
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号（根节点为1）
void buildTree(int s = 1, int e = n, int o = 1)
{
    if(s == e)  // 叶子节点（区间长度为1）
    {
        t[o] = a[s];  // 叶子节点值等于原始数组对应元素
        return;
    }
    
    int mid = (s + e) >> 1;  // 划分左右子区间（等价于(s+e)/2）
    // 递归构建左子树（覆盖[s, mid]）
    buildTree(s, mid, o << 1);
    // 递归构建右子树（覆盖[mid+1, e]）
    buildTree(mid + 1, e, o << 1 | 1);
    
    pushup(o);  // 合并左右子节点的值，更新当前节点
}

// 对当前节点覆盖的区间[s,e]执行异或更新（内部辅助函数）
// o: 当前节点编号，x: 待异或的值
void update(int s, int e, int o, ll x)
{
    // 异或性质：若区间长度为奇数，整体异或x等价于所有元素异或x后的结果
    // 若区间长度为偶数，所有元素异或x后，整体异或和不变（偶数个x异或抵消）
    t[o] ^= ((e - s + 1) & 1) ? x : 0;  // (e-s+1)&1 判断区间长度是否为奇数
    lz[o] ^= x;  // 记录懒标记（异或操作具有叠加性：x^x=0，可直接异或叠加）
}

// 下推懒标记（将当前节点的待异或值传递给子节点）
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
void pushdown(int s, int e, int o)
{
    if(!lz[o]) return;  // 若没有待传递的标记，直接返回
    
    int mid = (s + e) >> 1;       // 划分左右子区间
    int ls = o << 1;              // 左子节点编号
    int rs = o << 1 | 1;          // 右子节点编号
    
    // 左子树覆盖[s, mid]，传递懒标记
    update(s, mid, ls, lz[o]);
    // 右子树覆盖[mid+1, e]，传递懒标记
    update(mid + 1, e, rs, lz[o]);
    
    lz[o] = 0;  // 当前节点的懒标记已传递，清空
}

// 区间查询：求[l, r]区间的异或和
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接返回当前节点的异或和
    if(l <= s && e <= r) return t[o];
    
    // 下推懒标记（确保子节点的值是最新的）
    pushdown(s, e, o);
    
    ll res = 0;  // 存储查询结果（初始为0，异或的单位元）
    int mid = (s + e) >> 1;
    // 若左子区间与[l, r]有重叠，累加左子树的查询结果
    if(mid >= l) res ^= query(l, r, s, mid, o << 1);
    // 若右子区间与[l, r]有重叠，累加右子树的查询结果
    if(mid + 1 <= r) res ^= query(l, r, mid + 1, e, o << 1 | 1);
    
    return res;
}

// 区间更新：给[l, r]区间的每个元素异或x
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接更新当前节点
    if(l <= s && e <= r)
    {
        update(s, e, o, x);  // 调用内部函数执行异或更新
        return;
    }
    
    // 下推懒标记（确保子节点的值是最新的）
    pushdown(s, e, o);
    
    int mid = (s + e) >> 1;
    // 若左子区间与[l, r]有重叠，递归更新左子树
    if(mid >= l) add(l, r, x, s, mid, o << 1);
    // 若右子区间与[l, r]有重叠，递归更新右子树
    if(mid + 1 <= r) add(l, r, x, mid + 1, e, o << 1 | 1);
    
    pushup(o);  // 合并更新后的子节点值，更新当前节点
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    buildTree();  // 构建线段树
    
    while(q--)
    {
        int op, l, r;  // op:操作类型（1=更新，2=查询），l/r:操作区间
        cin >> op >> l >> r;
        if(op == 1)  // 区间异或：给[l, r]每个元素异或x
        {
            ll x; cin >> x;
            add(l, r, x);
        }
        else  // 区间查询：求[l, r]的异或和
        {
            cout << query(l, r) << '\n';
        }
    }
    
    return 0;
}

//5 3
//1 2 3 4 5
//1 1 3 2
//2 1 3
//2 4 5
//
//2
//1
