#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N], v;
int dfn[N]; //��¼�ڵ�ʱ���������Ƿ��߹� 
int low[N]; //�洢�ڵ��ܵ���ĵĻص㣨һ���߹��ĵ㣩����Сʱ���
int stk[N], top; //һ��ջ���洢�߹�����û�б�Ⱦɫ�ĵ�
int col[N]; //�洢�ڵ����ɫ
int c[N]; //����������¼ÿ����ɫ���������� 
int tot; //��ʾ��ʱ����ɫ����
int idx; //��ʱ��ʱ��� 
bitset<N> ins; //��instack���Ƿ���ջ�� 
//�ص㣺��ʽ���Ľ�����dfn��Ϊ0����ջ�С�ͨ�׵���⣬���������һ�������Ҹ����Ǳ�ĵ� 

void tarjan(int x) //tarjan�ı�����һ��dfs 
{
	// 1.��ʼ��dfn��low 
	dfn[x] = low[x] = ++idx;
	
	// 2.��ջ����� 
	stk[++top] = x;
	ins[x] = 1;
	
	// 3.�������г��㣨�ǳ��㲻�Ƕ��ӣ�u����ָ��ܶ�v����vֻ����һ�����ף� 
	for(auto& y : g[x])
	{
		//�ж��Ƿ��ǻص� 
		if(!dfn[y]) //��������û���ʣ���y����x�Ķ��� 
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]); //�������ʹ�������ջ����
		//��֮��һ������ʹ��ֲ���ջ���棬��������ڱ�������� 
	}
	
	if(dfn[x] == low[x]) //�ж��Ƿ񹹳����� 
	{
		tot++; //�¿�һ����ɫ 
		while(stk[top + 1] != x)
		{
			col[stk[top]] = tot; //Ⱦɫ 
			c[tot]++;  
			
			ins[stk[top--]] = 0; //ȡ����ǲ���ջ 
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	while(m--)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	
	for(int i = 1; i <= n; i++) //1��һ�������յĸ��ڵ㣬Ҫ����ÿһ����Ϊ���ڵ�Ŀ��� 
		if(!dfn[i]) tarjan(i);
		
	for(int i = 1; i <= tot; i++)
		if(c[i] > 1) v.push_back(c[i]);
	
	if(v.size())
	{
		sort(v.begin(), v.end());
		for(auto& y : v) cout << y << ' ';
	}
	else cout << -1;
	
	return 0;
}

//4 4
//1 2
//2 3
//3 1
//1 4
//
//3
