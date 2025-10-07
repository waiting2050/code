#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N];

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque<int> dq;//dq存放下标

	//求最大
	for (int i = 1; i <= n; i++)
	{
		//队头要在[i-k+1, i]里面，即要在检索的区域内  ps:i-(i-k+1)=k-1,但是是闭区间，所以k-1+1=k,刚好是长度为k的区间
		while (dq.size() && dq.front() <= i - k) dq.pop_front();//i-k是左端点左边的一个点，如果队头在左端点左边，弹出 
		while (dq.size() && a[dq.back()] <= a[i]) dq.pop_back();//令队头始终是最大的

		dq.push_back(i);

		if (i >= k) cout << a[dq.front()] << ' ';//i>=k,起码要等遍历完一个区间再输出 
	}
	cout << '\n';
	dq = deque<int>();//清空队列

	//求最小
	for (int i = 1; i <= n; i++)
	{
		while (dq.size() && dq.front() <= i - k) dq.pop_front();
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();

		dq.push_back(i);

		if (i >= k) cout << a[dq.front()] << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//8 3
//0 3 1 0 - 5 2 1 8
//
//3 3 1 2 2 8
//0 0 - 5 - 5 - 5 1
