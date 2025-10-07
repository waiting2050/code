// Problem: 可划分数组
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/105825/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;

int a[N], dp[N], l[N], r[N];//dp[i]为以i为结尾，最多划分多少段

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(r, 0x3f, sizeof(r));
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dp[i] = -2e9;
	
	for(int i = 1; i <= n; i++)//对每一个i，更新其左边和右边所需要的最近的质数。 
	//ps:如果一个区间[l,r]合法，那么该区间内每一个点的li>=l,ri<=r 
	{
		for(int j = i + 1; j <= n; j++)
			if(__gcd(a[i], a[j]) ^ 1) r[i] = min(r[i], j);
		for(int j = i - 1; j >= 1; j--)
			if(__gcd(a[i], a[j]) ^ 1) l[i] = max(l[i], j);
	}
	
	//for(int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << '\n';
	dp[0] = 0;
	for(int i = 1; i <= n; i++)//i是区间右端点，j是区间左端点
	{
		int lft = i;//lft是[j,i]间的每一个点，只要lft合法，就可以更新答案 
		for(int j = i; j >= 1; j--)//要从i开始，因为要先更新左端点lft为l[i](一开始j==i)
		{
			if(r[j] > i) lft = min(lft, l[j]);//如果右边不合法，那么这个j只能往左边找与他成对的。
			//由于min贪心，lft一定是区间内所有左端点最靠左的那一个，所以只要lft合法，那么所有端点都是合法的。
			 
			if(lft >= j) dp[i] = max(dp[i], dp[j - 1] + 1);//如果左边合法，dp要么继承，要么从以左端点结尾的dp+1 
		}
	}
	
	cout << max(dp[n], -1);
	
	return 0;
}

