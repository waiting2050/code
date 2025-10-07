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

//�ж��Ƿ�ʹ�ò��鼯��������
//�������漰��̬�ϲ����ϡ����ٲ����������ϣ�����Ҫ��Чά������/��ͨ��ʱ���ɿ��ǲ��鼯��
//��������Ҫ��ԾʽѰ�ҿ���λ�ã��籾�����С���������ĳ����У����鼯�������Ż�ʱ�临�Ӷȡ�

const int N = 2e5 + 9;
int pre[N], c[N];//pre�Ǽ�¼���ڵ�ģ�c��������

//һ�в���������Ը���																				
int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }//����+ѹ��|ͨ���ݹ��������Ҹ��������ڷ��ص�ʱ�򽫸�����ÿ���ӽڵ�
//int root(int x)	//û��·��ѹ����root��������ʱ���Ȩ��Ҫ�ָ�״̬�Ȳ���ʱ����ѹ��·��		
//{
//	while(pre[x] != x) x = pre[x];			
//	return x;					
//}

void merge(int x, int y) { pre[root(x)] = root(y); }//�������ĵ����ӣ�Ҳ���Ǻϲ�����

//bool is_con(int x, int y) { return root(x) == root(y); }//�ж��������Ƿ���һ�����ϣ����������ò���

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) pre[i] = i;//�Ƚ�ÿ�����Ի�����Ϊ�����Ȼ�Ի��ĵ���Ǹ��ڵ�

	while (m--)
	{
		int u, v; cin >> u >> v;

		merge(u, v);
	}

	for (int i = 1; i <= n; i++) c[root(i)]++;//ÿ��һ������ĳ���ڵ��£���ø��ڵ�ļ�����1
	
	vector<int> ans;
	for (int i = 1; i <= n; i++) if (c[i])ans.push_back(c[i]);//���ͳ�Ƶ��ĸ��ڵ����push�������������������
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
