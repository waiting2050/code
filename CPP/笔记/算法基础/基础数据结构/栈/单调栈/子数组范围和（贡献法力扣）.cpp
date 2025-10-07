
//˼·������O(n)������������ʽ�Ӳ�֣�ת��Ϊ���������ֵ����Сֵ�Ĳ����͡�
//�����ֵ����Сֵ˼·��һ���ģ�ֻҪ���һ����һ�����Ƽ��ɡ�
//Ҫ��ÿ����������ֵ�����Ի���˼·����ÿһ����Ϊ���ֵ�����Թ�Ͻ�������䣨Ҳ���ǹ��׷�����Ȼ��ע��߽�һ��ȡ��һ�߲�ȡ�ȼ��ɡ� 

class Solution 
{
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 0);
        int n = nums.size() - 1;
        vector<int> stk(n + 1), lmx(n + 1), rmx(n + 1), lmi(n + 1), rmi(n + 1);

        int top = 0;
        for(int i = 1; i <= n; i++)
        {
            while(top && nums[i] >= nums[stk[top]]) top--;

            lmx[i] = top ? stk[top] : 0;

            stk[++top] = i;
        }

        top = 0;
        for(int i = n; i >= 1; i--)
        {
            while(top && nums[i] > nums[stk[top]]) top--;

            rmx[i] = top ? stk[top] : n + 1;

            stk[++top] = i;
        }

        top = 0;
        for(int i = 1; i <= n; i++)
        {
            while(top && nums[i] <= nums[stk[top]]) top--;

            lmi[i] = top ? stk[top] : 0;

            stk[++top] = i;
        }

        top = 0;
        for(int i = n; i >= 1; i--)
        {
            while(top && nums[i] < nums[stk[top]]) top--;

            rmi[i] = top ? stk[top] : n + 1;

            stk[++top] = i;
        }

        long long sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += nums[i] * 1ll * (i - lmx[i]) * (rmx[i] - i) -
                   nums[i] * 1ll * (i - lmi[i]) * (rmi[i] - i);//ע����ת��Ϊlong long
            
        }

        return sum;
    }
};
