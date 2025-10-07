#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//旅行商问题，n在8以下可以暴力搜索，12以下可以剪枝搜索，20以下需要剪枝+状压 

const int N = 25;
struct P//因为点的参数可能为负数，所以用结构体存储 
{
	double x, y;
	int num;
	bool vis;
}p[N];
double d[N][33000], ans = DBL_MAX;//d数组一维表示当前点，二维表示之前的状态，存储经过二维的路径过来的距离 
int n;

double dis(P t1, P t2) {return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));}

void dfs(P t0, int dep, int sta, double di)//当前点, 层数，状态，距离
{
	if(di >= ans) return;
	
	if(dep == n)
	{
		ans = min(ans, di);
		return;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(p[i].vis) continue;
		
		//比如0010就表示从1->当前状态,00100110表示经过1,2,5到当前状态，
		//至于这几个点之间具体怎么转移无所谓，反正存的是最小，那么一定是最优秀的转移方案 
		int temp = sta | 1 << (i - 1);//因为编号是[1,n]，不是[0,n)所以i要减1 
		double dist = dis(t0, p[i]);
		
		if(!d[i][temp] || d[i][temp] > d[t0.num][sta] + dist)//如果没有被更新或者当前方案更优秀 
		{
			d[i][temp] = d[t0.num][sta] + dist;
			p[i].vis = 1;
			
			dfs(p[i], dep + 1, temp, di + dist);
			
			p[i].vis = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y;
		p[i].num = i;
	}
	
	P t0 = {0, 0, 0, 0};//得初始化，因为不是全局变量 
	dfs(t0, 0, 0, 0);
	
	printf("%.2f", ans);
	
	return 0;
}
//4
//1 1
//1 -1
//-1 1
//-1 -1
//
//7.41
//
//
//12
//1 0
//1 -1
//2 -1
//3 -4
//4 -4
//3 -5
//5 0
//6 0
//6 -1
//5 -4
//5 -5
//6 -5
//
//17.15
