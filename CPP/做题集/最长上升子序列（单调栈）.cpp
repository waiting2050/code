//描述
//
//小X性格很独特，如果她今天高兴度比上次一样或更高，她就会很善良，相反，如果她今天高兴度比上次低，她就会很凶！
//现在已经知道小X在N天里每天的高兴度M。根据这N天中她每天高兴度M，合理安排与她相处时间，使大家与小X友好相处尽量多天数
//（在小X善良的日子里可以与其友好相处，否则不可以）。现在要求计算出最多能和小X友好相处多少天。
//
//
//输入
//
//共2行，第一行为一个N，第二行为N个数，为小X每天的高兴程度M。
//
//
//输出
//
//共1个数，最多能和小X友好相处多少天。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int a[N];

vector<int> v;//作为单调递增栈
//O(nlogn)贪心、二分、单调栈
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//提高输入输出效率

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	v.push_back(a[1]);
	for (int i = 2; i <= n; i++)//运用贪心思想，保证v的长度始终是增长的
	{
		if (a[i] >= v.back())//如果大于等于就放入单调栈
			v.push_back(a[i]);
		else
			v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];//否则就检查栈里面的元素，找到第一个大于a[i]的元素位置进行替换
	}//如果算出的结果还没以前的长，会暂时保留以前的结果						//因为只要长度，所以可以逐渐用新的子序列替代旧的
	//当新序列长度 ≥ 原序列长度时，原序列已经被完全覆盖，现在就是以新序列为基础进行计算
	cout << v.size();

	return 0;
}
