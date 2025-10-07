#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//这道题采用前缀和思想，到下标为i位置时，选择了几个数。例如pre[i]>=pre[i-1]+0且pre[b]>=pre[a-1]+w.
//本题求的是最小值，所以用最长路 

const int N = 5e4 + 7;
const ll INF = 2e18;

struct Edge
{
	int y, w;
};

vector<Edge> g[N];
int n, m = 5e4;
ll d[N];

bool spfa(int st) //最长路与最长路区别只有两个地方，1：d[i]赋值为-INF；2：改为d[x]+w>d[y] 
{
	vector<int> cnt(m + 1);
	queue<int> q;
	bitset<N> inq;
	
	q.push(st);
	inq[st] = 1;
	for(int i = 1; i <= m; i++) d[i] = -INF; //不同点1 
	
	while(q.size())
	{
		int x = q.front(); q.pop(); inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{
			if(d[x] + w > d[y]) //不同点2 
			{
				if(++cnt[y] >= m + 1) return false; //这道题没有这个步骤也行，因为按题目说法，逻辑肯定是通的，不存在正环的可能 
				d[y] = d[x] + w;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a - 1].push_back({b, c});
	}
	
	//不用构建虚拟源点，因为经过了下面的步骤以后，整个图已经是联通了 
	for(int i = 1; i <= m; i++)
	{
		g[i - 1].push_back({i, 0});
		g[i].push_back({i - 1, -1}); //下一个位置的数最多比上一个位置的数大1，因为这道题是对于每个位置的数选或不选 
	}								//并非选几个，也就是说不能重复选。假如下一个位置大了2以上，说明下个位置的数选了多次 
	
	spfa(0);
	
	cout << d[m]; //题目问的是[1,5e4]范围的答案，m=5e4 
	
	return 0;
}

// 5
// 3 7 3
// 8 10 3
// 6 8 1
// 1 3 1
// 10 11 1
// 
// 6
