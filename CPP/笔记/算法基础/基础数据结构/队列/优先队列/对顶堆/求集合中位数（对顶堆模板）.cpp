#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll> q1;//q1�Ǵ����
priority_queue<ll, vector<ll>, greater<ll>> q2;//q2��С����

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		q1.push(x);//���뵽q1����q2ûӰ�� 
		
		//ȷ��q1.top<=q2.top 
		while(q1.size() && q2.size() && q2.top() < q1.top())
		{
			q2.push(q1.top());
			q1.pop();
		}
		
		//Ϊ������q1,q2�ķ�Χ��ȷ��q1,q2֮��Ĳ���0��1 
		while(q1.size() + 1 < q2.size())//ע�������+1���ܷ��ұ߱�-1���������������Ϊ�޷������ͣ����������ʱ 
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
