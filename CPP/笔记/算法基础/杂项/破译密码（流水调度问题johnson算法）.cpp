// Problem: 5. 破译密码【算法赛】
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/20288/learning/?contest_id=253
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;

struct P
{
    int u, v;
    double p;
    
    bool operator < (const P& t) const//Johnson算法的核心 
    {
    	return min(u, t.v) < min(v, t.u);
    }
}a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].u;
    for(int j = 1; j <= n; j++) cin >> a[j].v;

    sort(a + 1, a + 1 + n);
    
    ll ans = a[1].u, wait = a[1].v;
    for(int i = 2; i <= n; i++)//模拟选择过程 
    {
        if(wait >= a[i].u) wait = wait - a[i].u + a[i].v;
        else wait = a[i].v;
        
        ans += a[i].u;
    }
    ans += wait;
    
    cout << ans;
    
    return 0;
}

//4
//1 3 5 7
//6 5 1 4
//
//17
