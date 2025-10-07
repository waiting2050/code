
//思路：考虑O(n)做法。将所求式子拆分，转化为求区间最大值与最小值的差的求和。
//求最大值与最小值思路是一样的，只要求出一个另一个复制即可。
//要求每个区间的最大值，可以换个思路：以每一个数为最大值它可以管辖多少区间（也就是贡献法），然后注意边界一边取等一边不取等即可。 

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
                   nums[i] * 1ll * (i - lmi[i]) * (rmi[i] - i);//注意用转化为long long
            
        }

        return sum;
    }
};
