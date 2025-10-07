
//˼·������ͨ����ջ��ͬ���ǣ�����Ҫ��Ĳ�����ĳ��Ԫ�������Ԫ�ض�����Զ��Ԫ�ء�
//����ѭ������һ��ѭ������һ�������ݼ���ջ��ֻҪһ�����У���Ϊһ��ջ�Ͱ��������г�Ϊ���Ž�Ŀ��ܡ�
//Ϊʲô�أ���Ϊ��˵�϶���Խ����ԽСԽ�ã���Ȼ������������ߵ�Ԫ����Ū������������Ѿ�����С���ǾͲ����ٲ����������������ұ߶��Ҹ�С�ģ� 
//Ϊ���Ҷ˵���ң��ڶ���ѭ��Ҫ��������ȡ��ջ����Ҫ�ǿ���������ȡ
//С���ɣ�ֻҪ�ȵ�i>=res�Ϳ��ԣ���Ϊ��������Ҳ�����res�������� 

//����
//���룺[9,8,1,0,1,9,4,0,4,1]
//�����ݼ�Ԫ��:[9,8,1,0], ��Ӧ�±�:[0,1,2,3], �ϸ񵥵��ݼ�ջs:[0,1,2,3]
//j=9, nums[j]=1 > nums[s.top()]=nums[3]=0, pos=s.top()=3, pop��3, res=max(res, j-pos)=(0, 9-3)=6
//     nums[j]=1 = nums[s.top()]=nums[2]=1, pos=s.top()=2, pop��2, res=max(res, j-pos)=(6, 9-2)=7
//     nums[j]=1 < nums[s.top()]=nums[1]=8, ������һ��j
//j=8, nums[j]=4 < nums[s.top()]=nums[1]=8, ������һ��j
//j=7, nums[j]=0 < nums[s.top()]=nums[1]=8, ���ñ�����
//res=7 

class Solution 
{
public:
    int maxWidthRamp(vector<int>& nums)
    {
        nums.insert(nums.begin(), 0);
        int n = nums.size() - 1;
        vector<int> stk(n + 1);

        int top = 0;
        for(int i = 1; i <= n; i++) 
            if(!top || nums[i] < nums[stk[top]]) stk[++top] = i;
        
        int ans = 0;
        for(int i = n; i >= ans; i--)
        {
            while(top && nums[i] >= nums[stk[top]])
            {
                ans = max(ans, i - stk[top]);
                top--;
            }
        }

        return ans;
    }
};
