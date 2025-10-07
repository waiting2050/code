#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
ll a[N], stk[N], l[N], r[N], top;//l����a[i]���Ԫ���±꣬r�ұ�

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	//i=1,��a[i]�����
	for (int i = 1; i <= n; i++)
	{
		while (top && a[stk[top]] >= a[i]) top--;//Ѱ����ߵ�һ��<a[i]��Ԫ��

		if (!top) l[i] = 0;//���û�У�����l[i]=0������i=1,��ôi-0=1,Ҳ����˵ÿһ��Ԫ��Ĭ���Լ���ռ���һ��λ�õģ�
		else l[i] = stk[top];//����У��ͼ�¼�����±�

		stk[++top] = i;//��Ԫ��ѹ��ջ
	}

	top = 0;
	for (int i = n; i >= 1; i--)//i=n������a[i]���ұ�Ԫ��
	{
		while (top && a[stk[top]] > a[i]) top--;//Ѱ���ұߵ�һ��<=a[i]��Ԫ��

		if (!top) r[i] = n + 1;//ͬ���ģ�ÿ��Ԫ��Ҳռ�ұ�һ��λ��
		else r[i] = stk[top];

		stk[++top] = i;
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i] * (i - l[i]) * (r[i] - i);

	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5
//7 8 5 6 7
//
//86
