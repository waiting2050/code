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
int a[N], dep, n;//a��1~n��dep�ǲ���

bitset<N> vis;

void dfs(int dep)
{
	if (dep == n + 1) //������������������
	{
		for (int i = 1; i <= n; i++) cout << a[i] << " \n"[n == i];
		return;
	}

	for (int i = 1; i <= n; i++)//���������ӽڵ�,i�Ǵ�1��n�����Ի���С�������
	{
		if (vis[i]) continue;//�ñ�־�����ж�
		vis[i] = true;//�޸ı�־����
		a[dep] = i;

		dfs(dep + 1);//�����ӽڵ㣬����Ϊx+1

		//��ԭ��־��������ʾ��ת��
		vis[i] = false;
		a[dep] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	dfs(1);

	return 0;
}
