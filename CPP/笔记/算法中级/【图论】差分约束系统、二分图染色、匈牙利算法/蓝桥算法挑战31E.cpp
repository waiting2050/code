// Problem: 5. 学院交流【算法赛】
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/21070/learning/?contest_id=263
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 显然答案具有单调性，所以用二分。之后构造冲突图，只关心那些不符合条件的点对，只要这些点能成功分配
// 就一定有解。
// 也可以用拓展域并查集取代染色法，效率更高

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 500 + 7;

int a[N][N], col[N], n;

bool dfs(vector<int> g[], int x)
{
    for(auto& y : g[x])
    {
        if(col[y] == -1)
        {
            col[y] = col[x] ^ 1;
            if(!dfs(g, y)) return false;
        }
        else if(col[x] == col[y]) return false;
    }
    
    return true;
}

bool check(int x)
{
    vector<int> g[N];
    for(int i = 1; i <= n; i++) col[i] = -1;
    
    // 构造冲突图，不符合条件存入邻接表
    bool _1side = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i][j] < x)
            {
                g[i].push_back(j);
                g[j].push_back(i);
                _1side = false;
            }
        }
    }
    
    // _1side标记能否全放入一个集合
    if(_1side) return true;
    
    for(int i = 1; i <= n; i++)
    {
        if(col[i] == -1)
        {
            col[i] = -1;
            if(!dfs(g, i)) return false;
        }
    }
    
    return true;
}

void solve()
{
    cin >> n;
    
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            r = max(r, a[i][j]);
        }
    }
    
    r++;
    while(l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    
    cout << l;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _ = 1;
    while(_--) solve();

    return 0;
}

// 4
// 0 2 3 1
// 2 0 3 4
// 3 3 0 3
// 1 4 3 0
// 
// 3