#include<iostream>
using namespace std;
int dp[1001][1001],a1[2001],a2[2001],n,m;
int main()
{
   //dp[i][j]��ʾ��������ͷ��ʼ��ֱ����һ�����ĵ�iλ 
   //�͵ڶ������ĵ�jλ����ж��ٸ�������Ԫ�� 
   cin>>n>>m;
   for(int i=1;i<=n;i++)scanf("%d",&a1[i]);
   for(int i=1;i<=m;i++)scanf("%d",&a2[i]);
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
     {
     	//�������ͬ�����޷����¹���Ԫ�أ����Ǽ̳У�
     	dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //dp[i-1][j]��ʾ����a1[i]��ѡ��dp[i][j-1]��ʾ����a2[j]��ѡ
     	
     	//�����ǰ��A1[i]��A2[j]��ͬ���������µĹ���Ԫ�أ� ��ô
     	if(a1[i]==a2[j])
     	dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1); 
     }
   cout<<dp[n][m];
}

