//描述
//
//
//　　在C/C++语言中，整型所能表示的范围一般为-231到231（大约21亿）,即使long long型，一般也只能表示到-263到263。
//要想计算更加规模的数，就要用软件来扩展了，比如用数组或字符串来模拟更多规模的数及共运算。
//　　现在输入两个整数，请输出它们的乘积。
//
//输入
//
//输入描述:
//　　两行，每行一个正整数，每个整数不超过10000位
//输入样例:
//99
//101
//
//输出
//
//
//输出描述:
//　　一行，两个整数的乘积。
//输出样例:
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

//高精度乘高精度 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> mul(vector<int>& a, vector<int>& b)
{
	vector<int> res(a.size() + b.size(), 0);
	//从低位到高位处理 
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			int temp = a[i] * b[j] + res[i + j];//当前的乘积加上之前的进位 
			res[i + j] = temp % 10;
			res[i + j + 1] += temp / 10;//进位用+= 
		}
	}
	
	//去除前导0 
	while(res.size() > 1 && !res.back()) res.pop_back();
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string str1, str2; cin >> str1 >> str2;
	
	vector<int> a, b;
	//从高位到低位存储要反过来 
	for(int i = str1.size() - 1; i >= 0; i--) a.push_back(str1[i] - '0');
	for(int i = str2.size() - 1; i >= 0; i--) b.push_back(str2[i] - '0');
	
	vector<int> ans = mul(a, b);
	
	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	
	return 0;
}

//高精度*低精度 
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

