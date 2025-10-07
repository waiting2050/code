//����
//
//
//������C/C++�����У��������ܱ�ʾ�ķ�Χһ��Ϊ-231��231����Լ21�ڣ�,��ʹlong long�ͣ�һ��Ҳֻ�ܱ�ʾ��-263��263��
//Ҫ�������ӹ�ģ��������Ҫ���������չ�ˣ�������������ַ�����ģ������ģ�����������㡣
//������������������������������ǵĳ˻���
//
//����
//
//��������:
//�������У�ÿ��һ����������ÿ������������10000λ
//��������:
//99
//101
//
//���
//
//
//�������:
//����һ�У����������ĳ˻���
//�������:
//9999

// Problem: 
//     P1303 A*B Problem
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1303
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//�߾��ȳ˸߾��� 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> mul(vector<int>& a, vector<int>& b)
{
	vector<int> res(a.size() + b.size(), 0);
	//�ӵ�λ����λ���� 
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			int temp = a[i] * b[j] + res[i + j];//��ǰ�ĳ˻�����֮ǰ�Ľ�λ 
			res[i + j] = temp % 10;
			res[i + j + 1] += temp / 10;//��λ��+= 
		}
	}
	
	//ȥ��ǰ��0 
	while(res.size() > 1 && !res.back()) res.pop_back();
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string str1, str2; cin >> str1 >> str2;
	
	vector<int> a, b;
	//�Ӹ�λ����λ�洢Ҫ������ 
	for(int i = str1.size() - 1; i >= 0; i--) a.push_back(str1[i] - '0');
	for(int i = str2.size() - 1; i >= 0; i--) b.push_back(str2[i] - '0');
	
	vector<int> ans = mul(a, b);
	
	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	
	return 0;
}

//�߾���*�;��� 
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//vector<int> mul(vector<int>& a, int b)
//{
//	int t = 0;
//	vector<int> c;
//	for(int i = 0; i < a.size() || t; i++)
//	{
//		if(i < a.size()) t += a[i] * b;
//		c.push_back(t % 10);
//		t /= 10;
//	}
//	while(c.size() > 1 && !c.back()) c.pop_back();
//	
//	return c;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	
//	string ta; cin >> ta;
//	int b; cin >> b;
//	
//	vector<int> a;
//	for(int i = ta.size() - 1; i >= 0; i--) a.push_back(ta[i] - '0');
//	
//	vector<int> ans = mul(a, b);
//	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
//	
//	return 0;
//}

