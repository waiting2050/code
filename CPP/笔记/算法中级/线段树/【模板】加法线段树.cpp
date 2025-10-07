#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;  // 数据最大规模

int n;                  // 实际数据长度
ll a[N];                // 原始数组
ll t[N << 2];           // 线段树节点数组（大小为4*N，满足线段树需求）
ll lz[N << 2];          // 懒标记数组（存储待传递的区间增量）

// 向上更新当前节点的值（由左右子节点的值合并而来）
void pushup(int o)
{
    // 当前节点值 = 左子节点值 + 右子节点值（求和操作）
    t[o] = t[o << 1] + t[o << 1 | 1];
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
    
    int mid = (e + s) >> 1;  // 划分左右子区间（等价于(s+e)/2）
    // 递归构建左子树（覆盖[s, mid]）
    buildTree(s, mid, o << 1);
    // 递归构建右子树（覆盖[mid+1, e]）
    buildTree(mid + 1, e, o << 1 | 1);
    
    pushup(o);  // 合并左右子节点的值，更新当前节点
}

// 下推懒标记（将当前节点的待更新量传递给子节点）
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
void pushdown(int s, int e, int o)
{
    if(!lz[o]) return;  // 若没有待传递的标记，直接返回
    
    int mid = (s + e) >> 1;       // 划分左右子区间
    int ls = o << 1;              // 左子节点编号
    int rs = o << 1 | 1;          // 右子节点编号
    
    // 左子树更新：加上懒标记值 * 左子树区间长度
    t[ls] += lz[o] * (mid - s + 1);
    // 右子树更新：加上懒标记值 * 右子树区间长度
    t[rs] += lz[o] * (e - mid);
    
    // 左子节点继承懒标记（后续需传递给它的子节点）
    lz[ls] += lz[o];
    // 右子节点继承懒标记
    lz[rs] += lz[o];
    
    lz[o] = 0;  // 当前节点的懒标记已传递，清空
}

// 区间加法：给[l, r]区间的每个元素加上x
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内
    if(l <= s && e <= r)
    {
        // 更新当前节点值：加上x乘以区间长度
        t[o] += x * (e - s + 1ll);  // 1ll确保计算时转为长整型，避免溢出
        lz[o] += x;  // 记录懒标记，暂不传递给子节点
        return;
    }
    
    // 若当前节点有未传递的标记，先下推（确保子节点值正确）
    pushdown(s, e, o);
    
    int mid = (s + e) >> 1;
    // 若左子区间与[l, r]有重叠，递归更新左子树
    if(mid >= l) add(l, r, x, s, mid, o << 1);
    // 若右子区间与[l, r]有重叠，递归更新右子树
    if(mid + 1 <= r) add(l, r, x, mid + 1, e, o << 1 | 1);
    
    pushup(o);  // 合并更新后的子节点值，更新当前节点
}

// 区间查询：求[l, r]区间的元素和
// s: 当前节点覆盖的区间起点，e: 区间终点，o: 当前节点编号
ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
    // 若当前节点覆盖的区间完全在[l, r]内，直接返回当前节点值
    if(l <= s && e <= r) return t[o];
    
    // 若当前节点有未传递的标记，先下推（确保子节点值正确）
    pushdown(s, e, o);
    
    ll res = 0;
    int mid = (s + e) >> 1;
    // 若左子区间与[l, r]有重叠，累加左子树的查询结果
    if(mid >= l) res += query(l, r, s, mid, o << 1);
    // 若右子区间与[l, r]有重叠，累加右子树的查询结果
    if(mid + 1 <= r) res += query(l, r, mid + 1, e, o << 1 | 1);
    
    return res;
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
        if(op == 1)  // 区间加法：给[l, r]加x
        {
            ll x; cin >> x;
            add(l, r, x);
        }
        else if(op == 2)  // 区间查询：求[l, r]的和
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
//12
//9
