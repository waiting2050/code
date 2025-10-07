// Problem: 游戏高手
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/107879/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//思路：将所有胜负关系分为三种：1.链 2.环 3.点。如果是环，那么不论e、p怎么排，最终环的得分都是0，如果是点，那么点得分也是0（但是这两种情况对链有影响）。 
//只需要考虑链的情况即可。链里又分为三种可能，头、尾、中间。显然有优势头>中间>尾，可以观察到不论中间怎么排，实际得分只受头尾影响。
//（ps：从出入度的角度考虑，这个时候中间的点出入度之和为0，可以看作是孤立的点）也就是说头尾相同则为0，不同那么头对应+1，尾-1。
//进一步可以发现链的数量的奇偶性会影响得分。当偶数时，不论怎么排得分都为0。奇数时，肯定优先抢头的位置，头抢完以后抢点（将出入度和为0的情况统称为点）， 
//最后没得选了才是选尾。在没得选的情况下，要是p第一个选尾，就意味着p肯定要比e更多选一次（因为是奇数），而同理，选头的时候，e肯定比p多选一次 
//所以只有在这种情况e肯定得1分，否则都是0分。形式化的说，只有当链为奇数且点个数为偶数时得分才为1。 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int cd[N];

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cd[i] = 0;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		cd[u]++, cd[v]--;
	}
		
	int lin = 0, pnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cd[i] == 1) lin++;
		else if(!cd[i]) pnt++;
	}
	
	cout << ((lin & 1 && pnt % 2 == 0) ? 1 : 0) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//2
//4 3
//1 2
//2 4
//4 3
//7 5
//1 2
//2 3
//3 4
//5 6
//6 5
//
//1
//0
