//和之前求加法的最大子段和的思想是一样的，但这里不能再用0来作比了，因为一个负数*一个负数也可能直接变成max
//所以这个时候不仅需要max，还要min（绝对值大的都有成为最终max的潜力），然后就和常规最大子段和一样了，判断正负的事交给计算机就好 

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        int mx = nums[1], mi = nums[1], ans = nums[1];
        for(int i = 2; i <= n; i++)
        {
            int tmx = mx;
            mx = max({mx * nums[i], mi * nums[i], nums[i]});
            mi = min({tmx * nums[i], mi * nums[i], nums[i]}); //注意这个时候mx已经更新了 
            ans = max(ans, mx);
            //cout << ans << ' ' << mx << ' ' << mi << '\n';
        }

        return ans;
    }
};

//输入:nums=[2,3,-2,4]
//输出:6
//
//
//输入: nums = [-2,0,-1]
//输出: 0
