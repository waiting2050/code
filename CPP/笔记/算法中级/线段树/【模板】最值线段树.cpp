#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;  // 原始数组最大长度

int n;                  // 实际数组长度
ll a[N];                // 原始数组（1-based索引）
ll tMax[N];             // 线段树节点数组（存储区间最大值）
ll tMin[N];             // 线段树节点数组（存储区间最小值）
ll lz[N];               // 懒标记数组（存储待添加的增量）
ll inf = 2e18;          // 表示无穷大（用于初始化最小值查询）

// 向上更新当前节点的最大/最小值（由左右子节点合并）
void pushup(int o)
{
    // 当前节点的最大值 = 左子节点最大值 和 右子节点最大值 中的较大者
    tMax[o] = max(tMax[o << 1], tMax[o << 1 | 1]);
    // 当前节点的最小值 = 左子节点最小值 和 右子节点最小值 中的较小者
    tMin[o] = min(tMin[o << 1], tMin[o << 1 | 1]);
}

// 构建线段树
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号（根节点为1）
void buildTree(int s = 1, int e = n, int o = 1)
{
    if(s == e)  // 叶子节点（区间长度为1）
    {
        tMax[o] = tMin[o] = a[s];  // 叶子节点的最大/最小值均为自身
        return;
    }
    
    int mid = (s + e) >> 1;  // 划分左右子区间（等价于(s+e)/2）
    // 递归构建左子树（覆盖[s, mid]）
    buildTree(s, mid, o << 1);
    // 递归构建右子树（覆盖[mid+1, e]）
    buildTree(mid + 1, e, o << 1 | 1);
    
    pushup(o);  // 合并左右子节点的值，更新当前节点
}

// 对当前节点覆盖的区间[s,e]执行加法更新（内部辅助函数）
// o: 当前节点编号，x: 待添加的增量
void update(int s, int e, int o, ll x)
{
    tMax[o] += x;  // 最大值加上增量x
    tMin[o] += x;  // 最小值加上增量x
    lz[o] += x;    // 记录懒标记（待传递给子节点的增量）
}

// 下推懒标记（将当前节点的增量传递给子节点）
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

// 区间更新：给[l, r]区间的每个元素加上x
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接更新当前节点
    if(l <= s && e <= r)
    {
        update(s, e, o, x);
        return;
    }
    
    pushdown(s, e, o);  // 下推懒标记，确保子节点值正确
    
    int mid = (s + e) >> 1;
    // 若左子区间与[l, r]有重叠，递归更新左子树
    if(mid >= l) 
        // 错误：这里应该调用add递归，而非直接调用update
        // update(s, mid, o << 1, x);  // 错误行
        add(l, r, x, s, mid, o << 1);  // 正确行
    // 若右子区间与[l, r]有重叠，递归更新右子树
    if(mid + 1 <= r) 
        // 错误：同理，应调用add递归
        // update(mid + 1, e, o << 1 | 1, x);  // 错误行
        add(l, r, x, mid + 1, e, o << 1 | 1);  // 正确行
    
    pushup(o);  // 合并更新后的子节点值，更新当前节点
}

// 区间查询：求[l, r]区间的最大值
ll queryMax(int l, int r, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接返回最大值
    if(l <= s && e <= r) return tMax[o];
    
    pushdown(s, e, o);  // 下推懒标记，确保子节点值正确
    
    ll res = -inf;  // 初始化结果为负无穷
    int mid = (s + e) >> 1;
    
    // 若左子区间与[l, r]有重叠，递归查询左子树最大值
    if(mid >= l) res = max(res, queryMax(l, r, s, mid, o << 1));
    // 若右子区间与[l, r]有重叠，递归查询右子树最大值
    if(mid + 1 <= r) res = max(res, queryMax(l, r, mid + 1, e, o << 1 | 1));
    
    return res;
}

// 区间查询：求[l, r]区间的最小值
ll queryMin(int l, int r, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接返回最小值
    if(l <= s && e <= r) return tMin[o];
    
    pushdown(s, e, o);  // 下推懒标记，确保子节点值正确
    
    ll res = inf;  // 初始化结果为正无穷
    int mid = (s + e) >> 1;
    
    // 若左子区间与[l, r]有重叠，递归查询左子树最小值
    if(mid >= l) res = min(res, queryMin(l, r, s, mid, o << 1));
    // 若右子区间与[l, r]有重叠，递归查询右子树最小值
    if(mid + 1 <= r) res = min(res, queryMin(l, r, mid + 1, e, o << 1 | 1));
    
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q;  // 操作次数
    cin >> n >> q;
    // 读入原始数组（1-based索引）
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    buildTree();  // 构建线段树
    
    while(q--)
    {
        int op, l, r;  // op:操作类型（1=更新，2=查询），l/r:操作区间
        cin >> op >> l >> r;
        if(op == 1)  // 区间加法：给[l, r]每个元素加x
        {
            ll x; cin >> x;
            add(l, r, x);
        }
        else  // 区间查询：输出[l, r]的最大值和最小值
        {
            cout << queryMax(l, r) << ' ' << queryMin(l, r) << '\n';
        }
    }
    
    return 0;
}
