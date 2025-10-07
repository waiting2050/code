// Problem: ţţ��Լ��
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/116657/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//���������õ���ջ����ν�ĵ����ԣ�����֮���Ԫ�ؿ�����ȫ����ȡ��֮ǰ�ķǷ�Ԫ�ء�
//�Ա���Ϊ�����������к󣬿�������4��һ����������2��������δ�س��������4������ȫ����ȡ��2 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 7;

ll stk[N], a[N]; //a�洢ԭ���� 

void solve()
{
	int n; cin >> n;
	vector<ll> v; //v��ȥ��+�������±� 
	unordered_map<ll, int> mp, ans; //mp��ԭ����Ķ�Ӧ��ϵ��ֵ--ԭ�±꣩��ans�ǣ�ֵ--Ŀ���±꣩ 
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
		if(!mp[a[i]]) mp[a[i]] = i;
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = v.size();
	v.insert(v.begin(), 0);
	
	int top = 0;
	for(int i = 1; i <= m; i++)
	{
		while(top && v[i] % v[stk[top]] == 0) top--;
		ans[v[i]] = (top ? mp[v[stk[top]]] : -1);
		stk[++top] = i;
	}
	
	for(int i = 1; i <= n; i++) cout << ans[a[i]] << " \n"[i == n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 3
// 5
// 1 2 3 4 5
// 4
// 2 4 8 16
// 6
// 1 2 4 7 8 16
// 
// -1 -1 2 3 4
// -1 -1 -1 -1
// -1 -1 -1 3 4 4
