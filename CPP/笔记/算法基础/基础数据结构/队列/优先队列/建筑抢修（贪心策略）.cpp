// Problem: Luogu P4053
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4053
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P
{
	int x, y;
	
	bool operator < (const P& p) const//按照期限时长升序排序，期限严格（时间短）的放前面
	{
		return y > p.y;
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	priority_queue<P> pq;
	priority_queue<int> q;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		pq.push({x, y});
	}
	
	//模拟的思路：对每一个建筑，不管能不能修完都先放到队列里去，然后累计时长，进行判断。
	//判断：如果能修完计数+1，否则选出队列里用时最长的让它pop（注意这个时候当前建筑的修建时长已经在队列里了），这相当于一种优势取代劣势
	//因为反正将当前建筑加进去不能让计数+1，那干脆替换掉之前最差的那个（就算替换了再加上被换的那个也无法计数+1） 
	int cnt = 0;
	ll sum = 0;
	while(pq.size())
	{
		auto [x, y] = pq.top(); pq.pop();//注意这里别加引用&，否则pop以后变量混乱 
		
		sum += x;
		q.push(x);
		
		if(sum <= y) cnt++;
		else
		{
			int t = q.top(); q.pop();
			sum -= t;
		}
	}
	
	cout << cnt;
	
	return 0;
}

//4
//100 200
//200 1300
//1000 1250
//2000 3200
//
//3
