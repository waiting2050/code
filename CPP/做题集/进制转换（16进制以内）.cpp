//题目描述
//请你编一程序实现两种不同进制之间的数据转换。
//
//输入格式
//共三行，第一行是一个正整数，表示需要转换的数的进制 n (2≤n≤16)，第二行是一个 n 进制数，
//若 n>10 则用大写字母 A～F 表示数码 10～15，并且该 n 进制数对应的十进制的值不超过 10^9
// ，第三行也是一个正整数，表示转换之后的数的进制 m (2≤m≤16)。
//
//输出格式
//一个正整数，表示转换之后的 m 进制数。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string cri = "0123456789ABCDEF";

int ntoten(int n, string num)
{
	int res = 0;
	for(int i = 0; i < num.size(); i++)
	{
		if(num[i] >= '0' && num[i] <= '9')
			res = res * n + num[i] - '0';
		else res = res * n + num[i] - 'A' + 10;
	}
	
	return res;
}

string tentom(int num, int m)
{
	string res;
	while(num)
	{
		res = cri[num % m] + res;
		num /= m;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m;
	string num;
	
	cin >> n >> num >> m;
	
	cout << tentom(ntoten(n, num), m);
	
	return 0;
}

//16
//FF
//2
//
//11111111
