#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

struct Book
{
	int h, s, w;

	bool operator <(const Book& a)const//sort默认用小于号排序 
	{
		if (h == a.h && s == a.s) return w > a.w;
		if (h == a.h)return s > a.s;
		return h > a.h;				//优先对h进行降序排列 
	}
}b[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i].h >> b[i].s >> b[i].w;
	}

	sort(b + 1, b + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		cout << b[i].h << ' ' << b[i].s << ' ' << b[i].w << '\n';
	}

	return 0;
}
