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
int a[N], dq[N];//dq模拟deque

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int hh = 1, tt = 0;//hh即head,tt即tail，hh是队列左，tt是右。但初始化时，要令hh在tt右边

	//求最大
	for (int i = 1; i <= n; i++)
	{
		//队头要在[i-k+1, i]里面，即要在检索的区域内  ps:i-(i-k+1)=k-1,但是是闭区间，所以k-1+1=k,刚好是长度为k的区间
		//如果统计[i-k+1,i-1]，就用<i-k 
		while (hh <= tt && dq[hh] <= i - k) hh++;//当尾比头靠右（即队列非空），并且头在检索区域外，hh++(即头位置右移)
		while (hh <= tt && a[dq[tt]] <= a[i]) tt--;//如果队尾元素<=新增,tt--（相当于弹出队尾元素）

		dq[++tt] = i;//tt--会令结果偏左1位，所以++tt修正

		if (i >= k) cout << a[dq[hh]] << ' ';//i>=k,起码要等遍历完一个区间再输出 
	}
	cout << '\n';

	hh = 1, tt = 0;//清空队列

	//求最小
	for (int i = 1; i <= n; i++)
	{
		while (hh <= tt && dq[hh] <= i - k) hh++;
		while (hh <= tt && a[dq[tt]] >= a[i]) tt--;

		dq[++tt] = i;

		if (i >= k) cout << a[dq[hh]] << ' ';
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
