#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7, T = 20;
ll st[N][T], lg2[N];

// 获取区间[l, r]内的最大值
ll get_max(int l, int r)
{
    int k = lg2[r - l + 1]; // 计算区间长度对应的最大2的幂次k
    return max(st[l][k], st[r - (1 << k) + 1][k]); // 比较两个重叠区间的最大值
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 提高I/O操作的速度
    
    // 输入处理
    ll n, k; cin >> n >> k; // 输入数组大小n和查询条件k
    for(int i = 1; i <= n; i++) cin >> st[i][0]; // 输入数组元素，并初始化ST表的第一列（j=0），每个元素自己作为一个区间
    
    // 预计算lg2数组，用于快速查找合适的k值
    for(int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    
    // 构建ST表，对于每一个可能的区间长度2^j，填充st数组
    for(int j = 1; j <= T; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); // 更新区间最大值
        }
    }
    
    ll ans = 0; // 答案计数器
    for(int i = 1; i <= n; i++) // 枚举左端点
    {
        int l = i - 1, r = n + 1; // 初始化二分搜索的边界
        while(l + 1 != r) // 二分查找满足条件的最大右端点
        {
            int mid = (l + r) >> 1; // 计算中间位置
            if(get_max(i, mid) >= k) r = mid; // 如果区间最大值满足条件，则尝试更小的右端点
            else l = mid; // 否则，尝试更大的右端点
        }
        
        ans += n - r + 1; // 统计满足条件的区间数量
    }
    
    cout << ans; // 输出答案
    
    return 0;
}

// 4 3
// 1 2 3 4
// 
// 7

