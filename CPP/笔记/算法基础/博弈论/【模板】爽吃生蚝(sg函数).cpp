// sg函数解题常规套路（3步）
// 1. 建模：
//    - 将全局游戏拆分为多个独立子局面（如多堆石子拆为每堆单独子游戏）
//    - 明确每个局面的合法操作，即从当前局面能转移到哪些子局面（如取石子时“x颗取y颗→x-y颗”）
// 2. 算sg值：
//    - 边界：终止局面（无法操作，如0颗石子）的sg值 = 0
//    - 递归：收集当前局面所有可达子局面的sg值，取mex（最小未出现非负整数）作为当前sg值
//    - 优化：用记忆化（数组/哈希表）存储已算sg值，避免重复计算
// 3. 判胜负：
//    - 计算全局总sg值 = 所有独立子局面sg值的异或（XOR）
//    - 结论：总sg值≠0 → 当前玩家必胜；总sg值=0 → 当前玩家必败
// 核心逻辑：拆分局面→算sg→异或判胜负（子局面之间的胜负用异或连接）

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e3 + 7;

bitset<N> vis;
vector<int> primes;
unordered_map<int, int> sg;

// void init()
// {
	// vis[0] = vis[1] = 1;
	// for(int i = 2; i <= N / i; i++)
	// {
		// if(vis[i]) continue;
		// for(int j = i + i; j < N; j += i) vis[j] = 1;
	// }
// 	
	// primes.pb(1); // 题目里规定取1也可以
	// for(int i = 1; i < N; i++) if(!vis[i]) primes.pb(i);
// }

int getsg(int x) // 注释部分是sg模板，用来找规律
{
	// if(!x) return 0; // 如果为0说明没得取，返回0
	// if(sg.count(x)) return sg[x]; // 记忆化搜索
// 	
	// unordered_set<int> st; // 对每个点找所有可达点
	// for(auto& y : primes)
	// {
		// if(x < y) break;
		// st.insert(getsg(x - y));
	// }
// 	
	// for(int i = 0; i < N; i++) if(!st.count(i)) return sg[x] = i; // 对所有可达点求mex
	return x % 4;
}

void solve()
{
	int n; cin >> n;
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		ans ^= getsg(x);
	}
	cout << ((!ans) ? "NO" : "YES") << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	//init(); // 预处理质数
	
	//for(int i = 0; i < N; i++) cout << getsg(i) << ' '; // 打表找规律
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 3
// 3
// 27 41 5
// 7
// 33 5 53 73 77 23 55
// 9
// 89 69 73 29 23 97 73 65 54

// YES
// YES
// NO