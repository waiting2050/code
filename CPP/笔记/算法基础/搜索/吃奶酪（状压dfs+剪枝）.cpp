#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//���������⣬n��8���¿��Ա���������12���¿��Լ�֦������20������Ҫ��֦+״ѹ 

const int N = 25;
struct P//��Ϊ��Ĳ�������Ϊ�����������ýṹ��洢 
{
	double x, y;
	int num;
	bool vis;
}p[N];
double d[N][33000], ans = DBL_MAX;//d����һά��ʾ��ǰ�㣬��ά��ʾ֮ǰ��״̬���洢������ά��·�������ľ��� 
int n;

double dis(P t1, P t2) {return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));}

void dfs(P t0, int dep, int sta, double di)//��ǰ��, ������״̬������
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
		
		//����0010�ͱ�ʾ��1->��ǰ״̬,00100110��ʾ����1,2,5����ǰ״̬��
		//�����⼸����֮�������ôת������ν�������������С����ôһ�����������ת�Ʒ��� 
		int temp = sta | 1 << (i - 1);//��Ϊ�����[1,n]������[0,n)����iҪ��1 
		double dist = dis(t0, p[i]);
		
		if(!d[i][temp] || d[i][temp] > d[t0.num][sta] + dist)//���û�б����»��ߵ�ǰ���������� 
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
	
	P t0 = {0, 0, 0, 0};//�ó�ʼ������Ϊ����ȫ�ֱ��� 
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
