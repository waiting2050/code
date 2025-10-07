#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v, a;	//a�������룬v���������������

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int x;
	while(cin >> x) a.push_back(x);
	
 	 // ���� Dilworth �����������л�����Ҳ��������������� 
	 // ���ݵҶ���˹����Dilworth's Theorem������ƫ���У���С�����ֵ���������������Ĵ�С��
	 // ���������ķ��ϸ���������� ����������Ԫ�صȼ����ҵ� ��ϸ�ݼ������� �ĳ��ȡ�
	 // ���������ķ��ϸ�ݼ������� ����������Ԫ�صȼ����ҵ� ��ϸ���������� �ĳ��ȡ�
	v.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i] > v.back()) v.push_back(a[i]);
		else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	int h = v.size();
	v.clear();
	
	reverse(a.begin(), a.end());//���ش��ڵ��ڵ�
	
	v.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i] >=v.back()) v.push_back(a[i]);
		else v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	
	cout << v.size() << '\n' << h;
  	
  	return 0;
}

//389 207 155 300 299 170 158 65
//
//6
//2
