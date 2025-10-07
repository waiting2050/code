#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<int> q1;//大根堆
priority_queue<int, vector<int>, greater<int>> q2;//小根堆

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, w; cin >> n >> w;

	for(int i = 1; i <= n; i++)
	{
		int t = max(1, i * w / 100);//求第k位数中的k 
		
		int x; cin >> x;
		q2.push(x);
		
		while(q1.size() && q2.size() && q1.top() > q2.top())
		{
			q1.push(q2.top());
			q2.pop();
		}
		
		//注意只能针对q2这么操作，不然答案会出错(q2存的是成绩依次往下的，所以q2里的t，就是目标，而q1里的t是倒数第t名) 
		while(q2.size() < t)
		{
			q2.push(q1.top());
			q1.pop();
		}
		
		while(q2.size() > t)
		{
			q1.push(q2.top());
			q2.pop();
		}
		
		cout << q2.top() << ' ';
	}
	
	return 0;
}

