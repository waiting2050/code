// Problem:  Common Generator
// Contest: Virtual Judge - CodeForces
// URL: https://vjudge.net/problem/CodeForces-2029E
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e5 + 7;
bitset<N> vis;//0��ʾ������,1����
vector<int> primes;
int minp[N], a[N];

void euler(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), minp[i] = i;
		
		for(int j = 0; j < primes.size() && i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			minp[i * primes[j]] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//����û�����������
	int p = 0;
	for(int i = 1; i <= n; i++)
		if(!vis[a[i]]) p = a[i];
	if(!p)
	{
		cout << "2\n";
		return;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(p == a[i]) continue;
		if(!vis[a[i]] && p ^ a[i])//��һ�������������������н�
		{
			cout << "-1\n";
			return;
		}
		
		if(a[i] & 1)//����ʱ
		{
			if(a[i] - minp[a[i]] < 2 * p)//ͨ����ȥ��С�������ӣ�һ��������������������Ϊż���ж�
			{
				//p��������a[i]-minp����һ�������a[i]
				//��Ϊminp��a[i]�����ӣ�����minp|a[i],minp|minp,���Դ�a[i]-minp��һ��������ȡ��minp
				cout << "-1\n";
				return;
			}
		}
		else
		{
			if(a[i] < 2 * p)//��Ϊp�������������С���ӣ���������a[i]Ҫ>2p
			{
				cout << "-1\n";
				return;
			}
		}
	}
	
	cout << p << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	euler(4e5 + 7);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
// 4
// 3
// 8 9 10
// 4
// 2 3 4 5
// 2
// 147 154
// 5
// 3 6 8 25 100000
// 
// 2
// -1
// 2
// 3
