#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 17;

int a[N][N], n, m;
bitset<N> mt[N];//1��ʾ�ڣ�0��ʾ��
int dx[] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
 
bool inmp(int x, int y) {return x >= 0 && x < n && y >= 0 && y < m;}
 
//���Ź������򣬿��ڸ��������ܲ��ܵ�����Ŀ���� 
bool check(int x, int y)
{
	if(a[x][y] == -1) return true;
	
	int cnt = 0;
	for(int i = 0; i < 9; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(!inmp(nx, ny)) continue;
		cnt += mt[nx][ny];
	}
	
	return cnt == a[x][y];
}

//��ÿ����checkһ�飬��Ϊ��ֻ֦���ų�һ������� 
bool checkall()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!check(i, j)) return false;
		}
	}
	
	return true;
}

void dfs(int cnt)
{
	if(cnt == n * m - 1)
	{
		if(!checkall()) return;
		
		for(int i = 0; i < n; i++)//������Ŀ˵������Ψһ�⣬����ֱ��������� 
		{
			for(int j = 0; j < m; j++)
			{
				cout << mt[i][j];
			}
			cout << '\n';
		}
		return;
	}
	
	int x = cnt / m, y = cnt % m;
	if(x - 1 >= 0 && y - 1 >= 0 && !check(x - 1, y - 1)) return;//����Ҫ�ļ�֦����x,y����ɫȷ����������ôx-1,y-1�ĺϷ��ԾͿ����ж��� 
	if(x == n - 1 && y - 1 >= 0 && !check(x, y - 1)) return;//�����һ��ʱ�����ÿ�����һ�ж���Ӱ�죬���Զ�x,y-1�ĺϷ����ж� 
	if(y == m - 1 && x - 1 >= 0 && !check(x - 1, y)) return;//ͬ�� 
	
	int nx = (cnt + 1) / m, ny = (cnt + 1) % m;
	mt[nx][ny] = 0;//һ������ʡ���������Ȼ��©ѡ�� 
	dfs(cnt + 1);
	mt[nx][ny] = 1;
	dfs(cnt + 1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char ch; cin >> ch;
			if(ch == '_') a[i][j] = -1;
			else a[i][j] = ch - '0';
		}
	}
	
	dfs(-1);
	
	return 0;
}

//6 8
//_1__5_1_
//1_4__42_
//3__6__5_
//___56___
//_688___4
//_____6__
//
//00011000
//00111100
//01000010
//11111111
//01011110
//01111110
