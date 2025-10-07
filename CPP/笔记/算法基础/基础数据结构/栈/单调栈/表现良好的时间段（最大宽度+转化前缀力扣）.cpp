
//˼·���Գ���8Сʱ�ļ���1���������-1������ǰ׺��pre��
//��ʽ���ģ�i < j,pre[i] > pre[j]��������⡣���ʱ�������ת��Ϊ��֮ǰ������ȵ����⡣ 

class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        hours.insert(hours.begin(), 0);
        int n = hours.size() - 1;
        vector<int> stk(n + 1), pre(n + 1);

        for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (hours[i] > 8 ? 1 : -1);
        int top = 0;
        for(int i = 1; i <= n; i++)
            if(!top || pre[i] < pre[stk[top]]) stk[++top] = i;
        
        int ans = 0;
        for(int i = n; i >= ans; i--)
        {
            if(pre[i] > 0) ans = max(ans, i);//������Ҫ����
			//��Ȼ�����±귶Χ��[1,n]��������˵����ȡ��0(ǰ׺�͵�����֮��)�� 
            while(top && pre[i] > pre[stk[top]])
            {
                ans = max(ans, i - stk[top]);
                top--;
            }
        }

        return ans;
    }
};
