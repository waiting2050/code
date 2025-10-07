//����
//
//�˻ʺ����⣬��һ�����϶����������⣬�ǻ����㷨�ĵ��Ͱ�����
//�������ǹ����������������˹����ɪ����1848���������8X8��Ĺ��������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥����
//�����������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ����ж����ְڷ���
//��˹��Ϊ��76�ַ�����1854���ڰ��ֵ�������־�ϲ�ͬ�����߷�����40�ֲ�ͬ�Ľ⣬����������ͼ�۵ķ������92�ֽ����
//Ҫ�������ҳ����е�92�ַŷ���


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

const int N = 8;

//���������������Խ�������
pair<int, int> r[100];
bool c[100], md[100], sd[100];//md���Խ���,sd���Խ���
//����colһ��8�У�ֻ��Ҫ�ж�ĳһ���Ƿ��зŹ��Ϳ����ˣ����ö����ά���飬��Լ�ռ��ʱ��

void print()
{
	for (int i = 1; i <= N; i++)
		cout << "(" << r[i].first << "," << r[i].second << ")";
	cout << '\n';
}

void dfs(int dep)//dep����ȣ�Ҳ�ǵڼ��ţ�����ڶ�����ǵڶ���
{
	if (dep > N)
	{
		print();
		return;
	}
	for (int j = 1; j <= N; j++)
	{
		if (!c[j] && !md[j - dep + N] && !sd[j + dep])
		{
			r[dep].first = dep, r[dep].second = j;
			c[j] = true, md[j - dep + N] = true, sd[dep + j] = true;

			dfs(dep + 1);

			c[j] = false, md[j - dep + N] = false, sd[dep + j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	dfs(1);

	return 0;
}
