#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

struct P
{
	ll v;//a[x]+b[y]�������кϲ���ֵ 
	int x, y;//�ֱ��¼a��b���±� 
	
	bool operator < (const P& p) const
	{
		return v > p.v;//����ֵ�������� 
	}
};
priority_queue<P> pq;
int a[N], b[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) pq.push({b[1] + a[i], i, 1});
	
	for(int i = 1; i <= n; i++)
	{
		ll v = pq.top().v;
		int x = pq.top().x, y = pq.top().y; pq.pop();
		cout << v << ' ';
		if(y + 1 <= n) pq.push({a[x] + b[y + 1], x, y + 1});//ÿ���������Сֵ�󣬼�������̽��
		//���磬a[2]+b[1]�ǵ�ǰ��Сֵ����Ϊb[1]+a[1,n]�Ѿ�������У���ô������a[2]+b[2]��������С�� 
	}
	
	return 0;
}

//3
//2 6 6
//1 4 8
//
//3 6 7
