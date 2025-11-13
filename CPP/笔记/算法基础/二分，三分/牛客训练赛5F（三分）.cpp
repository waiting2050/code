// Problem: 牛牛战队的比赛地
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120454/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 既然比赛场地在x轴，那么枚举x，计算其与每个点距离，求最大值mx。容易想到，答案肯定在x轴的某个点，从左靠近时mx逐渐
// 减小，过了这个点，mx逐渐增大，曲线近似为凸二次函数，于是用三分枚举x即可。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define eb emplace_back
#define fi first
#define se second

const double EPS = 1e-4;
const int N = 1e5 + 7;

int n;
pair<double, double> a[N];

double dis(pair<double, double> p, double x)
{
	return (p.fi - x) * (p.fi - x) + p.se * p.se;
}

double check(double x)
{
	double mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, dis(a[i], x));
	
	return mx;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	
	double l = -1e5, r = 1e5;
	while(l + EPS <= r)
	{
		double lm = l + (r - l) / 3;
		double rm = r - (r - l) / 3;
		if(check(lm) < check(rm)) r = rm;
		else l = lm;
	}
	
	cout << sqrtl(check(l));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// 0 0
// 2 0
// 0 2

// 2