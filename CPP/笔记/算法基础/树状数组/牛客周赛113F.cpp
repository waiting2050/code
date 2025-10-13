// Problem: 二小姐的区间查询
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/119225/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题很明显可以看出来是单点修改+区间查询，但查询的东西比较复杂
// 其实就是找a[i]*a[j]%495==0，有多少对(i,j)。可以先将495分解因数
// 495=3²*5*11,由因子个数公式（https://blog.csdn.net/c_circle/article/details/78725468）可知有12个可能的因数
// 即1,3,5,9,11,15,33...... 不如将每个a[i]拆成与495的最大的因数（唯一的），那么最多出现12个数，将其存储在可以更新的结构中
// 在区间查询时，找这个区间里这12个数分别出现了几次，对每个因数，枚举另外的因数（注意别重复），再相乘（注意因数相同要特判）
// 这份代码开了12个树状数组去维护因数的出现次数

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7, B = 495;

// 核心变量说明：
// t[15][N]：15个树状数组（实际用12个，对应495的12个因子），t[i][x]维护“因子g[i]”在位置x的前缀和（统计出现次数）
// a[N]：存储数组元素（实际存“元素与495的gcd”，简化乘积倍数判断）
// g[15]：存储495的所有正因子（共12个，idx为因子总数）
// h[500]：映射表，key=495的因子，value=该因子在g数组中的索引（快速定位树状数组）
// c[15]：临时数组，存储查询区间内每个因子的出现次数
// n：数组长度
ll t[15][N], a[N], g[15], h[500], c[15], n;

int lowbit(int x) {return x & -x;}

void update(int k, ll tr[], int x) {for(int i = k; i <= n; i += lowbit(i)) tr[i] += x;}

ll query(int k, ll tr[])
{
	ll res = 0;
	for(int i = k; i; i -= lowbit(i)) res += tr[i];
	
	return res;
}

void solve()
{
	int q; cin >> n >> q;
	
	int idx = 0;
	for(int i = 1; i <= B; i++)
	{
		if(B % i) continue;
		
		g[++idx] = i;
		h[i] = idx;
	}
	
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		a[i] = __gcd(a[i], (ll)B);
		update(i, t[h[a[i]]], 1);
	}
	
	while(q--)
	{
		int op; cin >> op;
		if(op == 1)
		{
			int x, y; cin >> x >> y;
			update(x, t[h[a[x]]], -1);
			a[x] = __gcd(y, (int)B);
			update(x, t[h[a[x]]], 1);
		}
		else
		{
			int l, r; cin >> l >> r;
			for(int i = 1; i <= idx; i++) c[i] = query(r, t[i]) - query(l - 1, t[i]);
			
			ll ans = 0;
			for(int i = 1; i <= idx; i++)
			{
				for(int j = i; j <= idx; j++)
				{
					if(g[i] * g[j] % B) continue;
					if(i ^ j) ans += c[i] * c[j];
					else ans += (c[i] - 1) * c[i] >> 1;
				}
			}
			
			cout << ans << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5 3
// 1 1 1 1 495
// 2 1 5
// 1 1 495
// 2 1 5
// 
// 4
// 7