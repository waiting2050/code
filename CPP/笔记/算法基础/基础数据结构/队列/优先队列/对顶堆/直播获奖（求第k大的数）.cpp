#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<int> q1;//�����
priority_queue<int, vector<int>, greater<int>> q2;//С����

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, w; cin >> n >> w;

	for(int i = 1; i <= n; i++)
	{
		int t = max(1, i * w / 100);//���kλ���е�k 
		
		int x; cin >> x;
		q2.push(x);
		
		while(q1.size() && q2.size() && q1.top() > q2.top())
		{
			q1.push(q2.top());
			q2.pop();
		}
		
		//ע��ֻ�����q2��ô��������Ȼ�𰸻����(q2����ǳɼ��������µģ�����q2���t������Ŀ�꣬��q1���t�ǵ�����t��) 
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

