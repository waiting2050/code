// 1.这道题一开始想到每次给一个减数b，往前找有多少a[i]分别是<b和>=b去计算贡献求和，涉及到区间修改和查询以及单点修改，可以用线段树
// 去维护，但是要注意对一个[l,r]其中的a[i]可能<b，因此还需要维护最小值，当最小值<0，减去其贡献，但是这样代码会过于复杂。

// 2.于是有第二种做法，与其找每个b以前的a，不如找每个a以后的b，那么可以用前缀和去计算b，对每个a[l]，二分找到r使得sum_b[r-1]-sum_b[l-1]
// <a[i]，而sum_b[r]-sum_b[l-1]>=a[i]，那么a[i]对[l,r-1]贡献是b[i]，对[r]贡献是a[i]-(sum_b[r-1]-sum_b[l-1])，这可以用差分来维护

// 3.但是方法2还是有点麻烦，既然都对b用前缀和了，想到可以将每个a[i]加上b的前缀，当b的前缀和>=修改后的a[i]时，这个位置就是断点，
// 前后的贡献有区别，这样本质还是从a去找sum_b什么时候超过a，但是利用了前缀的性质，让a和b在同一起跑线，可以被比较，
// 如果不用前缀的性质，那么每次更新a都会是O(k)的，k就是没有死亡的雪人数量

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

ll a[N];
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll pre = 0;
	for(int i = 1; i <= n; i++)
	{
		ll b, ans = 0; cin >> b;
		pq.push(a[i] + pre);
		ll npre = pre + b;
		while(pq.size())
		{
			ll x = pq.top();
			if(x <= npre)
			{
				ans += x - pre;
				pq.pop();
			}
			else break;
		}
		ans += ll(pq.size()) * b;
		pre = npre;
		
		cout << ans;
		if(i ^ n) cout << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// 10 10 5
// 5 7 2

// 5 12 4