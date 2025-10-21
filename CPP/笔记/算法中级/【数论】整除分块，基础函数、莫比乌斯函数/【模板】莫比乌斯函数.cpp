#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e7 + 7;

int mu[N];
bitset<N> vis;
vector<int> primes;

void solve()
{
	int x; cin >> x;
	cout << mu[x] << '\n';
}

// 与普通欧拉筛不同在于多了mu数组，三条给mu赋值的语句分别对应莫比乌斯函数的三种情况
void init(int n)
{
	mu[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), mu[i] = -1;
		for(int j = 0; j < primes.size() && 1ll * i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0) 
			{
				mu[i * primes[j]] = 0; // 这里不写也可以，反正默认初始化为0
				break;
			}
			mu[i * primes[j]] = -mu[i];			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	init(1e7);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 20
// 920
// 839
// 654
// 604
// 91
// 408
// 462
// 503
// 485
// 220
// 207
// 982
// 210
// 968
// 816
// 887
// 633
// 150
// 854
// 72
// 
// 0
// -1
// -1
// 0
// 1
// 0
// 1
// -1
// 1
// 0
// 0
// 1
// 1
// 0
// 0
// -1
// 1
// 0
// -1
// 0