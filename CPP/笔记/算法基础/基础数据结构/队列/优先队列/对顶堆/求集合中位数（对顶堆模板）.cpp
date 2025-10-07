#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll> q1;//q1是大根堆
priority_queue<ll, vector<ll>, greater<ll>> q2;//q2是小根堆

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		q1.push(x);//加入到q1或者q2没影响 
		
		//确保q1.top<=q2.top 
		while(q1.size() && q2.size() && q2.top() < q1.top())
		{
			q2.push(q1.top());
			q1.pop();
		}
		
		//为了限制q1,q2的范围，确保q1,q2之间的差是0或1 
		while(q1.size() + 1 < q2.size())//注意这里的+1不能放右边变-1，否则会它的类型为无符号整型，会溢出，超时 
		{
			q1.push(q2.top());
			q2.pop();
		}
		while(q1.size() > q2.size())
		{
			q2.push(q1.top());
			q1.pop();
		}
		
		if(i & 1) cout << q2.top() << ' ';
		else cout << (q1.top() + q2.top()) / 2 << ' ';
	}
	
	return 0;
}

// 5
// 1 2 3 4 5
// 
// 1 1 2 2 3
