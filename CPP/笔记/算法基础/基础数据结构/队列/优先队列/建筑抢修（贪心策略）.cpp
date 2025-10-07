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
	
	bool operator < (const P& p) const//��������ʱ���������������ϸ�ʱ��̣��ķ�ǰ��
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
	
	//ģ���˼·����ÿһ�������������ܲ������궼�ȷŵ�������ȥ��Ȼ���ۼ�ʱ���������жϡ�
	//�жϣ�������������+1������ѡ����������ʱ�������pop��ע�����ʱ��ǰ�������޽�ʱ���Ѿ��ڶ������ˣ������൱��һ������ȡ������
	//��Ϊ��������ǰ�����ӽ�ȥ�����ü���+1���Ǹɴ��滻��֮ǰ�����Ǹ��������滻���ټ��ϱ������Ǹ�Ҳ�޷�����+1�� 
	int cnt = 0;
	ll sum = 0;
	while(pq.size())
	{
		auto [x, y] = pq.top(); pq.pop();//ע������������&������pop�Ժ�������� 
		
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
