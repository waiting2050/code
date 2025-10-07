#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//st表有一段区间会重复，如果重复的这段区间，比如max(a,a)=a，gcd(a,a)=a重复的部分还是等于自己就有可能用st表 

const int N = 1e5 + 7, T = 17;
int a[N];
int minst[N][20], maxst[N][20], gcdst[N][20], lg2[N];

int get_max(int l, int r)
{
	int k = lg2[r - l + 1];
	return max(maxst[l][k], maxst[r - (1 << k) + 1][k]);
}

int get_min(int l, int r)
{
	int k = lg2[r - l + 1];
	return min(minst[l][k], minst[r - (1 << k) + 1][k]);
}

int get_gcd(int l, int r)
{
	int k = lg2[r - l + 1];
	return __gcd(gcdst[l][k], gcdst[r - (1 << k) + 1][k]);
}

void solve() 
{
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++)
    	minst[i][0] = maxst[i][0] = gcdst[i][0] = a[i];
    	
    for(int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    
    for(int j = 1; j <= lg2[n]; j++)
    {
    	for(int i = 1; i + (1 << j) - 1 <= n; i++)
    	{
    		minst[i][j] = min(minst[i][j - 1], minst[i + (1 << (j - 1))][j - 1]);
    		maxst[i][j] = max(maxst[i][j - 1], maxst[i + (1 << (j - 1))][j - 1]);
    		gcdst[i][j] = __gcd(gcdst[i][j - 1], gcdst[i + (1 << (j - 1))][j - 1]);
    	}
    }
    
    while(q--)
    {
    	int l, r; cin >> l >> r;
    	cout << get_max(l, r) << ' ' << get_min(l, r) << ' ' << get_gcd(l, r)<< '\n';
    }
}

int main()
 {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//2
//9 1
//7 7 5 2 7 7 5 3 7 
//2 8
//7 1
//5 1 3 3 7 7 7 
//1 6
//
//7 2 1
//7 1 1
