#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 7;
int pre[3 * N];

//find存的其实是有向边，find(a)==find(b+n)意思是b可以吃a，find(a)==find(b)表示他们是同种生物（等价） 
int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	//3n表示三个集合A，B，C，设定B吃A，C吃B，A吃C
	//ps：（不同集合之间使用==是判断捕食关系，相同集合使用==是判断友好关系） 
	for(int i = 1; i <= n * 3; i++) pre[i] = i;
	
	int cnt = 0;
	while(k--)
	{
		int op, x, y; cin >> op >> x >> y;
		if(x > n || y > n)
		{
			cnt++;
			continue;
		}
		
		if(op == 1)//将两种生物合并为同种 
		{
			//如果x可能被y吃掉，或者y可能被x吃掉 
			if(find(x) == find(y + n) || find(y) == find(x + n)) cnt++;
			else
			{
				//合并为同种 
				pre[find(x)] = find(y);
				pre[find(x + n)] = find(y + n);
				pre[find(x + 2 * n)] = find(y + 2 * n);
			}
		}
		else//增加捕食关系 ，x吃y 
		{
			//如果两种生物等价，或者y可以吃x 
			if(find(x) == find(y) || find(y + n) == find(x)) cnt++;
			else
			{
				//增加捕食关系 
				pre[find(x + n)] = find(y);
				pre[find(x + 2 * n)] = find(y + n);
				pre[find(x)] = find(y + 2 * n);
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}

// 100 7
// 1 101 1
// 2 1 2
// 2 2 3
// 2 3 3
// 1 1 3
// 2 3 1
// 1 5 5
// 
// 
// 3
