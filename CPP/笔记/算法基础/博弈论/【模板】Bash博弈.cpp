#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// Bash博弈的关键在于观察到当N为M+1的倍数时，先手必败，无论怎么选，后手总是可以让当前石
// 子数量再变为M+1的倍数，并最终变为0，使得先手失败。
// 当N不是M+1的倍数时，先手可以通过一次合适的操作使得剩余的石子数变为M+1的倍数，从而
// 获得必胜的位置，把必败态抛给对手。
void solve()
{
	int n, m; cin >> n >> m;
	
	cout << ((n % (m + 1) == 0) ? "NO" : "YES") << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}
