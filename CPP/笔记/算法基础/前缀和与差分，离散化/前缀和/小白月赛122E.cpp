// Problem: AsubB
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/119664/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题很容易想到找前后缀，然后n^2枚举，若前后缀加起来的长度>=中间段的长度则计数+1
// 但这里的前后缀不好处理，因为这里的前后缀并不是单点的，而是代表一段区间
// 将本题加入笔记是因为前后缀的更新比较特殊，并不是简单由前一个或后一个更新而来

// 也可以用二分枚举右端点再用双指针判断是否为子串，或者直接用双指针替换二分

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e3 + 7;

// pre[i]表示从第i位开始a[i:i+len]可以匹配a[1:i-1]len位，suf同理
int a[N], pre[N], suf[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 2; i < n; i++)
	{
		int l = 1, r = n;
		while(l < i && i + pre[i] <= n) // 注意这里用i+pre[i]更新，pre[i]即len
		{
			if(a[l] == a[i + pre[i]]) pre[i]++;
			l++;
		}
		
		while(r > i && i - suf[i] >= 1)
		{
			if(a[r] == a[i - suf[i]]) suf[i]++;
			r--;
		}
	}
	
	int ans = 0;
	for(int i = 2; i < n; i++)
		for(int j = i; j < n; j++)
			ans += pre[i] + suf[j] >= j - i + 1; // pre[i]和suf[j]可能重合，即有一些字符既在前缀出现又在后缀出现
			
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 9
// 9 9 8 2 4 4 3 5 3
// 
// 5