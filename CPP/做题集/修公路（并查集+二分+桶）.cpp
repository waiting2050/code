#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int pre[N], c[N];
vector<int> v;//v�洢ÿ����ͨ���С��������3�����У���ô��С��Ϊ3 

void init(int n)
{
	for(int i = 1; i <= n; i++)
		pre[i] = i;
}

int find(int x) {return pre[x] = (pre[x] == x ? x : find(pre[x]));}

void merge(int u, int v) {pre[find(u)] = find(v);}

//���ĺ���
//��������ͨ���Ϊ���ࣺ1.ֻ��һ������ 2.��������������
//˼·���ܹ��������·-������м�ĵ�·�� >= һ����������·�� 
bool check(int k)
{
	ll cnt1 = 0, temp = 0;//cnt1�洢��һ�࣬temp��¼����������Ҳ�����ܹ����������������·�� 
	for(auto& y : v)
	{
		if(y == 1) cnt1++;
		else temp += min(y, k);//��������=����ͨ���������ĳ�����������ö�ٳ��Ŀ���������ȡС 
	}
	
	ll sum = temp - 2 * (v.size() - 1 - cnt1);//v.size-1������˵��������ͨ�飬��ôһ����Ҫ2����·������ 
	return sum >= cnt1;						  //Ϊʲô*2����Ϊa��b������һ��·=a����һ��+b����һ�����ܹ��������·������ظ������ˣ� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	init(n);
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		merge(u, v);
	}
	
	for(int i = 1; i <= n; i++)	c[find(i)]++;
	for(int i = 1; i <= n; i++)
		if(find(i) == i) v.push_back(c[i]);	
	
	ll l = -1, r = 1e9;
	while(l + 1 != r)
	{
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	
	cout << (check(r) ? r : -1);//ע��<<�����ȼ���?:�ߣ�����Ҫ������ 
	
	return 0;
}

//4 2
//1 2
//3 4
//
//1
