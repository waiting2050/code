#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N], idx;
struct Node
{
	int val, son[2];
}t[N * 32];//a[i]���1e9,��2^30��С�����Կ���2^31�η��㹻�� 

void insert(int x)
{
	int o = 0;//0����������ĸ��ڵ㣬����ÿ�δ�0��ʼ 
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;//y��0��1 
		int& u = t[o].son[y];//�жϵ�ǰ�ڵ���ָ�����һ��Ϊy�ĵ��Ƿ���� 
		
		if(!u) u = ++idx;//����������̬���㣬�������򲻹� 
		o = u;//���µ�ǰ�ڵ�ı�� 
	}
}

int getmax(int x)
{
	int o = 0, res = 0;
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int u = t[o].son[y], v = t[o].son[!y];
		if(v)
		{
			o = v;
			res |= 1 << i;
		}
		else o = u;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	insert(a[1]);//��ĿҪ�����������Ľ�����ȷŽ�ȥһ�� 
	
	int ans = 0;
	for(int i = 2; i <= n; i++) 
	{
		ans = max(ans, getmax(a[i]));
		insert(a[i]);
	}
	
	cout << ans << '\n';
	
	return 0;
}

// 5
// 1 3 2 4 5
// 
// 7
