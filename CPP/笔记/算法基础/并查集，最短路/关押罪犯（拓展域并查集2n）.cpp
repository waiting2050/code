#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e5 + 7, N = 4e4 + 7;
struct P
{
	int u, v, w;
	
	bool operator < (const P& t) const
	{
		return w > t.w;
	}
}p[M];
int pre[N], ans;//ans��ʼ��Ϊ0����Ϊ�п������з��˱������ֿ� 

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	//��Ϊ[n+1,2n]�Ĳ���Ҫ�洢[1,n]�ĵ��ˣ����Գ�ʼ��2n 
	for(int i = 1; i <= n << 1; i++) pre[i] = i;
	
	for(int i = 1; i <= m; i++) cin >> p[i].u >> p[i].v >> p[i].w;
	sort(p + 1, p + 1 + m);
	
	for(int i = 1; i <= m; i++)
	{
		int u = p[i].u, v = p[i].v, w = p[i].w;
		
		//ͬ��һ�������൱�ڱ��ؽ�ͬһ������ 
		if(find(u) == find(v))
		{
			//ֻҪӰ��������һ�ԣ��ҵ���break 
			ans = w;
			break;
		}
		
		//u��v����һ����������v(u)�ĵ��˼���u(v)���ڵļ��ϣ�����u��һ���ֻ�ܺ�v��һ�� 
		pre[find(u)] = find(v + n);
		pre[find(v)] = find(u + n);
	}
	
	cout << ans;
	
	return 0;
}

// 4 6
// 1 4 2534
// 2 3 3512
// 1 2 28351
// 1 3 6618
// 2 4 1805
// 3 4 12884
// 
// 3512
