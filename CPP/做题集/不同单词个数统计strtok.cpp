//问题描述
//编写一个程序，输入一个句子，然后统计出这个句子当中不同的单词个数。例如：对于句子“one little two little three little boys”，
//总共有5个不同的单词：one, little, two, three, boys。
//说明：（1）由于句子当中包含有空格，所以应该用gets函数来输入这个句子；（2）输入的句子当中只包含英文字符和空格，单词之间用一个空格隔开；
//（3）不用考虑单词的大小写，假设输入的都是小写字符；（4）句子长度不超过100个字符。
//输入格式：输入只有一行，即一个英文句子。
//输出格式：输出只有一行，是一个整数，表示句子中不同单词的个数。


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

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	char str[120];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	set<string> unique;

	char* token = strtok(str, " ");
	while (token != nullptr)
	{
		unique.insert(token);
		token = strtok(nullptr, " ");
	}

	cout << unique.size();

	return 0;
}
