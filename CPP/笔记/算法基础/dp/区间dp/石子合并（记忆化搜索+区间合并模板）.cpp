//int dfs(int l, int r) 
//{
//    if (l == r) return 0;
//    if (f[l][r] != INT_MAX) return f[l][r];
//    
//    for (int i = l; i < r; ++i)
//        f[l][r] = min(f[l][r], dfs(l, i) + dfs(i + 1, r) + a[r] - a[l - 1]);
//        
//    return f[l][r];
//}

#include <bits/stdc++.h>
using namespace std;

int a[1005], f[1005][1005], n;

int dfs(int l, int r) 
{
    if (l == r) return 0;//自己与自己合并，代价为0
    if (f[l][r] != INT_MAX) return f[l][r];//记忆化，已经求解的直接返回
    
    for (int i = l; i < r; ++i)
        f[l][r] = min(f[l][r], dfs(l, i) + dfs(i + 1, r) + a[r] - a[l - 1]);

    return f[l][r];
}

int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = INT_MAX;

    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    
    cout << dfs(1, n);
    
    return 0;
}
