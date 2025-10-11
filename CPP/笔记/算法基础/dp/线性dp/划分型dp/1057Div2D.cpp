// Problem: CF 2153 D
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 可以先将其看成划分为若干元素相同子段的最小代价（非环形），dp[i]=min(dp[i],d[j]+cost(j,i)),但是这样会是两重循环，
// 仔细考虑合并的规则，发现与工厂选址问题类似，子段内每个元素都要向中位数看齐，既然这样，干脆每两个元素放一起是最合适的
// 但是要考虑到奇偶性，也可能划分出3段。
// ps：比如说有一种特殊情况，即若干个相同元素本来就在一起，但此时将这若干元素拆成若干组2、3也是成立的，
// 因为2,3可以表示比他们大的任意数


//硬币问题：
// 若两个正整数 a 和 b 互质（即它们的最大公约数 gcd(a,b）=1），则存在一个最大的正整数 N，使得N无法
// 用a*x +b*y 的形式表示（其中×、y 为非负整数，即x≥0、y≥0）；且这个最大不可表数为a*b－a-b

// 当 a=2、b=3 时，由于 gcd(2,3)=1（互质），代入公式可得“最大不可表数"为 2*3－ 2－ 3 = 1。这意味
// 着：所有大于1的正整数，都能通过2和3的非负整数组合表示一一也就是你记忆中"2、3可以组成比它们大
// 的任何数"的本质（严格来说，是“比1大的任何数"，而2、3 本身及更大的数自然都包含在内）。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[N << 1];

ll f(ll x, ll y) {return max(x, y) - min(x, y);};

ll f(ll x, ll y, ll z) {return max({x, y, z}) - min({x, y, z});}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = INF;
	for(int k = 1; k <= 3; k++)  // 由于是环形的，所以要特判
	{   // 通过循环移位，将a[1,2,3]分别放开头，因为有可能n,1,2一组，或n,1一组
		vector<ll> dp(n + 7, INF);
		dp[0] = 0;
		for(int i = 2; i <= n; i++)
		{
			if(i >= 2) dp[i] = min(dp[i], dp[i - 2] + f(a[i], a[i - 1]));
			if(i >= 3) dp[i] = min(dp[i], dp[i - 3] + f(a[i], a[i - 1], a[i - 2]));
		}
		ans = min(ans, dp[n]);
		
		for(int i = 2; i <= n; i++) swap(a[i - 1], a[i]);
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 4
// 5
// 1 1 1 1 1
// 4
// 2 100 99 3
// 5
// 2 2 5 9 5
// 6
// 1 1 1 2 1 2
// 
// 0
// 2
// 4
// 1