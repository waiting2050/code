#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
int pre[N];
struct P
{
	int x, y, op;
	
	bool operator < (const P& t) const
	{
		return op > t.op;
	}
}p[N];
vector<int> X;

int ls(int x){return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;}

int find(int x){return pre[x] = (pre[x] == x ? x : find(pre[x]));}

void solve()
{
	int n; cin >> n;
	X.clear();
	
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y >> p[i].op;
		X.push_back(p[i].x), X.push_back(p[i].y);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	for(int i = 1; i <= X.size(); i++) pre[i] = i;
	sort(p + 1, p + 1 + n);
	
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		if(p[i].op) pre[find(ls(p[i].x))] = find(ls(p[i].y));
		else
		{
			if(find(ls(p[i].x)) == find(ls(p[i].y)))
			{
				cout << "NO\n";
				flag = false;
				break;
			}
		}
	}
	
	if(flag) cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

//2
//2
//1 2 1
//1 2 0
//2
//1 2 1
//2 1 1
//
//NO
//YES
//
//
//2
//3
//1 2 1
//2 3 1
//3 1 1
//4
//1 2 1
//2 3 1
//3 4 1
//1 4 0
//
//YES
//NO
