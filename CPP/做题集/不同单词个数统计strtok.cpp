//��������
//��дһ����������һ�����ӣ�Ȼ��ͳ�Ƴ�������ӵ��в�ͬ�ĵ��ʸ��������磺���ھ��ӡ�one little two little three little boys����
//�ܹ���5����ͬ�ĵ��ʣ�one, little, two, three, boys��
//˵������1�����ھ��ӵ��а����пո�����Ӧ����gets����������������ӣ���2������ľ��ӵ���ֻ����Ӣ���ַ��Ϳո񣬵���֮����һ���ո������
//��3�����ÿ��ǵ��ʵĴ�Сд����������Ķ���Сд�ַ�����4�����ӳ��Ȳ�����100���ַ���
//�����ʽ������ֻ��һ�У���һ��Ӣ�ľ��ӡ�
//�����ʽ�����ֻ��һ�У���һ����������ʾ�����в�ͬ���ʵĸ�����


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
