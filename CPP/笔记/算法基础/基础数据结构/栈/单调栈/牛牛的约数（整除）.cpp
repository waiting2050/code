// Problem: 牛牛的约数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/116657/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//核心是利用单调栈，所谓的单调性，就是之后的元素可以完全优势取代之前的非法元素。
//以本题为例，升序排列后，可以整除4的一定可以整除2，反过来未必成立，因此4可以完全优势取代2 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 7;

ll stk[N], a[N]; //a存储原数组 

void solve()
{
	int n; cin >> n;
	vector<ll> v; //v是去重+排序后的下标 
	unordered_map<ll, int> mp, ans; //mp是原数组的对应关系（值--原下标），ans是（值--目标下标） 
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
		if(!mp[a[i]]) mp[a[i]] = i;
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = v.size();
	v.insert(v.begin(), 0);
	
	int top = 0;
	for(int i = 1; i <= m; i++)
	{
		while(top && v[i] % v[stk[top]] == 0) top--;
		ans[v[i]] = (top ? mp[v[stk[top]]] : -1);
		stk[++top] = i;
	}
	
	for(int i = 1; i <= n; i++) cout << ans[a[i]] << " \n"[i == n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 3
// 5
// 1 2 3 4 5
// 4
// 2 4 8 16
// 6
// 1 2 4 7 8 16
// 
// -1 -1 2 3 4
// -1 -1 -1 -1
// -1 -1 -1 3 4 4
