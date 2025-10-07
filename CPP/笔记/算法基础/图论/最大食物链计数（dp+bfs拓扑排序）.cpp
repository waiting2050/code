// Problem: Luogu P4017
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4017
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//�������� 
//��ͼ���У���������Topological Sorting����һ�������޻�ͼ��DAG, Directed Acyclic Graph�������ж�����������С��Ҹ����б���������������������
//1.ÿ�����������ֻ����һ�Ρ�
//2.������һ���Ӷ��� A ������ B ��·������ô�������ж��� A �����ڶ��� B ��ǰ�档
//���ܣ�������xǰ�����ܵ���x�����нڵ�yi���ȴ���һ�� 
//��������ͨ�����������򡱾���������ϵ�����񣬹ؼ���Ҫά��һ�����Ϊ0�Ķ���ļ��ϡ�

//�ܽ�һ�£����������������ĸ���Ҫ���裺
//1.��ʼ�����У������Ϊ 0 �Ľڵ������С�
//2.ȡ�����ף���������ߣ����ܹ�����ĵ���ȼ�һ��ͬʱά�������顣
//3.���ڴ�ʱһ�������ȱ�Ϊ 0����ô���������С�
//4.�ص��ڶ�����ֱ������Ϊ�ա�

//һ�������ַ����ж��ܷ���������
//1.��1~n����ĳһ��rd[i]!=0
//2.�������ܳ��Ȳ�Ϊn 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 80112002;

const int N = 5e3 + 7;

int rd[N], cd[N], dp[N];//��ȣ����ȣ�ʳ������������ 
vector<int> g[N];//��ͼ 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b; cin >> a >> b;//a��b�ԣ���a->b����aΪ����bΪ�룩 
		rd[b]++, cd[a]++;//b�����+1����ָ��b��·����+1��a�ĳ���+1������a������·��+1 
		g[a].push_back(b);
	}
	
	queue<int> q;//bfs�Ķ��� 
	for(int i = 1; i <= n; i++)
	{
		if(!rd[i])//������Ϊ0�������У������䱾��ʳ��������Ϊ1 
		{
			q.push(i);
			dp[i] = 1;
		}
	}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		for(auto& y : g[t])
		{
			dp[y] = (dp[y] + dp[t]) % MOD;//�����ʳ������=�����е�+������ 
			rd[y]--;//ÿ���ۼӺ󣬽������-1 
			if(!rd[y]) q.push(y);//���õ�û����㣬��������Ҳ��ӣ�ά�����Ϊ0�ĵ�ļ��ϣ� 
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!cd[i])//���û�г��㣬˵���������յĲ�ʳ�� 
		 ans = (ans + dp[i]) % MOD;
	}
	
	cout << ans;
	
	return 0;
}

// 5 7
// 1 2
// 1 3
// 2 3
// 3 5
// 2 5
// 4 5
// 3 4
// 
// 5
