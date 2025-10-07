#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 7;
bitset<N> vis;
vector<int> primes;
int minp[N];//与模板不同的是增加了存储最小质因子的数组 

void euler(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), minp[i] = i;//如果是质数，那么最小质因子就是它本身 
		
		for(int j = 0; j < primes.size() && i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			minp[i * primes[j]] = primes[j];//如果是合数，存入最小质因子 
			if(i % primes[j] == 0) break;
		}
	}
}

void solve()
{
	int n; cin >> n;
	
	while(n ^ 1)
	{
		int p = minp[n];//取出最小质因子 
		
		cout << p << ' ';
		while(n % p == 0) n /= p;//比如12=2*2*3，2会重复出现，但是答案只要取一次，所以用while循环 
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

