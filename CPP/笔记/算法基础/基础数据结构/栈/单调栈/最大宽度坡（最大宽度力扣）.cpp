
//思路：跟普通单调栈不同的是，这里要求的不是离某个元素最近的元素而是最远的元素。
//两次循环，第一次循环构建一个单调递减的栈（只要一个就行，因为一个栈就包含了所有成为最优解的可能。
//为什么呢？因为左端点肯定是越靠左越小越好，既然这样，把最左边的元素先弄进来，如果它已经是最小的那就不必再操作，否则找在他右边而且更小的） 
//为了右端点最靠右，第二次循环要反向，依次取出栈顶，要是可以再往下取
//小技巧：只要比到i>=res就可以，因为再往下找也不会比res更优秀了 

//举例
//输入：[9,8,1,0,1,9,4,0,4,1]
//单调递减元素:[9,8,1,0], 对应下标:[0,1,2,3], 严格单调递减栈s:[0,1,2,3]
//j=9, nums[j]=1 > nums[s.top()]=nums[3]=0, pos=s.top()=3, pop出3, res=max(res, j-pos)=(0, 9-3)=6
//     nums[j]=1 = nums[s.top()]=nums[2]=1, pos=s.top()=2, pop出2, res=max(res, j-pos)=(6, 9-2)=7
//     nums[j]=1 < nums[s.top()]=nums[1]=8, 遍历下一个j
//j=8, nums[j]=4 < nums[s.top()]=nums[1]=8, 遍历下一个j
//j=7, nums[j]=0 < nums[s.top()]=nums[1]=8, 不用遍历了
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
