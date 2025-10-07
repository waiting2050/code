#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 7;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	 
	bitset<N> vis;
	vector<int> primes;
	
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i);
		
		for(int j = 0; j < primes.size() && i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0) break;
		}
	}
	
	return 0;
}
