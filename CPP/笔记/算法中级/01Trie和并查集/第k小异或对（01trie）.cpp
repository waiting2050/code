#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

struct Node
{
	int val, son[2];
}t[N << 5];

struct P
{
	int id, t, x, k;
	
	bool operator<(const P& p) const
	{
		return t < p.t;
	}
};
vector<P> v;
int a[N], ans[N], idx;

void insert(int x)
{
	int o = 0;
	t[o].val++;//���ڵ����+1 
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int& u = t[o].son[y];//���������� 
		
		if(!u) u = ++idx;//�����ھͶ�̬���� 
		o = u;//���µ�ǰ�ڵ� 
		t[o].val++;//���µ�ǰ�ڵ���� 
	}
}

int query(int x, int k)
{
	int o = 0, res = 0;
	for(int i = 30; i >= 0; i--)
	{
		int y = x >> i & 1;
		int u = t[o].son[y], v = t[o].son[!y];//����Ժ�u��С�㣬v�Ǵ�� 
		
		if(u && k <= t[u].val) o = u;//���ȷ������� 
		else
		{
			o = v;
			k -= u ? t[u].val : 0;//��Ϊ0��Ϊ���ڵ㣬��ֱ�Ӽ�ȥ���ڵ�Ȩֵ��Ȼ�Ǵ���� 
			res |= 1 << i;//��ͬ�������Ϊ1 
		} 
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//�ȶ�tԪ�ؽ�������������Ϊÿ��ѯ��[1,t]֮���Ԫ�أ����t�ǻ��ҵ���ô����Ҫ���϶�01trie���в����ɾ�� 
	for(int i = 1; i <= q; i++)
	{
		int t, x, k; cin >> t >> x >> k;
		v.push_back({i, t, x, k});
	}
	sort(v.begin(), v.end());
	
	int now = 0;
	for(auto&[id, t, x, k] : v)
	{
		while(now < t) insert(a[++now]);
		ans[id] = query(x, k);//�Ȼᰴ��ѯ��˳����� 
	}
	
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	
	return 0;
}

//5 3
//1 5 3 4 3
//3 100 2
//5 20 4
//1 30 1
//
//101
//23
//31
