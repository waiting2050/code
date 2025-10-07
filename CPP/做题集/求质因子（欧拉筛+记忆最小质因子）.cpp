#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 7;
bitset<N> vis;
vector<int> primes;
int minp[N];//��ģ�岻ͬ���������˴洢��С�����ӵ����� 

void euler(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), minp[i] = i;//�������������ô��С�����Ӿ��������� 
		
		for(int j = 0; j < primes.size() && i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			minp[i * primes[j]] = primes[j];//����Ǻ�����������С������ 
			if(i % primes[j] == 0) break;
		}
	}
}

void solve()
{
	int n; cin >> n;
	
	while(n ^ 1)
	{
		int p = minp[n];//ȡ����С������ 
		
		cout << p << ' ';
		while(n % p == 0) n /= p;//����12=2*2*3��2���ظ����֣����Ǵ�ֻҪȡһ�Σ�������whileѭ�� 
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	euler(1e7);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 3
// 9
// 12
// 30
// 
// 3
// 2 3
// 2 3 5

