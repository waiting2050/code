// Problem: 魔法卷轴
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/107879/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//思路：这道题难办在只有在恰当的时间爆炸才行，也就是说，必须提前附魔，在关键时间才能触发爆炸。
//可以发现一种必输的状态，就是在一个时间同时存在两个及以上已附魔的法师需要处理（已经预处理过后），那么贪心肯定要避免这种情况出现。
//怎么去找这种贪心策略呢？首先想到肯定要先排序，然后尽可能把法师之间的距离拉大，才能有更多余裕。那么肯定要想办法让法师尽量往两边靠。
//比如说最后的法师最好用冰冻，倒数第二位法师如果冰冻不会影响最后一位法师，就冰冻，否则燃烧。（为什么不对头处理？因为边界不好处理） 
//处理的过程中如果出现冲突，也就是前文提到的必输态，那么直接no。在预处理完以后，还要判断时间上来不来得及。
//因为要附魔、爆炸，起码需要两秒，当然也可以选择提前附魔，这一切都需要时间足够。举个例子，1 5 5，预处理以后变成2 4 6，
//于是从左往右判断时间上来不来得及。 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	map<int, int> mp;//这里不用unordered_map，因为之后需要从小到大遍历map 
	for(int i = n; i >= 1; i--)
	{
		int x = a[i] - 1, y = a[i] + 1;
		
		if(!mp[y]) mp[y] = 1;
		else if(!mp[x]) mp[x] = 1;
		else
		{
			cout << "NO\n";
			return;
		}
	}
	
	ll sum = 0, pre = 0;
	for(auto& [x, y] : mp)
	{
		sum += x - pre;
		pre = x;
		sum -= 2;
		if(sum < 0)
		{
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//2
//3
//5 1 5
//2
//1 2
//
//YES
//NO
//
//
//4
//3
//3 5 5
//3
//6 6 6
//2
//2 3
//7
//41 42 42 43 43 44 46
//
//YES
//NO
//YES
//YES
