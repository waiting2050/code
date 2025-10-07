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

const int N = 15;
int a[N], n;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin>>n;
	for (int i = 1; i <= n; i++) a[i] = i;

	do
	{
		for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
	} while (next_permutation(a + 1, a + 1 + n));//标准库的字典序排列

	return 0;
}
//反过来排列 
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

const int N = 15;
int a[N], n;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin>>n;
	for (int i = 1; i <= n; i++) a[i] = n + 1 - i;

	do
	{
		for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
	} while (prev_permutation(a + 1, a + 1 + n));//标准库的字典序排列

	return 0;
}
