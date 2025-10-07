#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

//判断是否使用并查集的条件：
//当问题涉及动态合并集合、快速查找所属集合，或需要高效维护区间/连通性时，可考虑并查集。
//尤其在需要跳跃式寻找可用位置（如本题的最小可用数）的场景中，并查集能显著优化时间复杂度。

const int N = 2e5 + 9;
int pre[N], c[N];//pre是记录父节点的，c用来计数

//一切操作都是针对根的																				
int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }//查找+压缩|通过递归来给查找根，并且在返回的时候将根赋给每个子节点
//int root(int x)	//没有路径压缩的root函数，有时候带权，要恢复状态等操作时不能压缩路径		
//{
//	while(pre[x] != x) x = pre[x];			
//	return x;					
//}

void merge(int x, int y) { pre[root(x)] = root(y); }//将所给的点连接，也就是合并操作

//bool is_con(int x, int y) { return root(x) == root(y); }//判断两个点是否在一个集合，不过本题用不到

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) pre[i] = i;//先将每个点自环，因为最后依然自环的点就是父节点

	while (m--)
	{
		int u, v; cin >> u >> v;

		merge(u, v);
	}

	for (int i = 1; i <= n; i++) c[root(i)]++;//每有一个点在某父节点下，则该父节点的计数加1
	
	vector<int> ans;
	for (int i = 1; i <= n; i++) if (c[i])ans.push_back(c[i]);//最后将统计到的父节点计数push到容器，方便排序输出
	sort(ans.begin(), ans.end());

	for (auto& ele : ans) cout << ele << ' ';

	return 0;
}
//5 2
//1 2
//1 3
//
//1 1 3
//https://blog.csdn.net/the_zed/article/details/105126583
