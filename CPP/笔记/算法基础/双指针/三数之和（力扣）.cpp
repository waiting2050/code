
//思路：首先要做过前置的两数之和题目，在一个有序数组（升序）中用左右指针去控制和的大小，复杂度O(n)。
//那么三数之和可以转化为：先枚举外层i，然后想办法让两数之和等于-nums[i]，复杂度O(n^2)。
//但是题目还要求不能重复，这部分注释会在代码中展示。 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
	{
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> v;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i - 1] == nums[i]) continue;//去重。如果第一个数字相同，后两个凑出第一个数的方案也会是相同的。 
            //两个小优化 
			if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;//最小的三个数加起来比0大，那么后面的只会更大 
            if(nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;//如果当前数加上最大的两个数小于0，那么中间的所有数都不会是答案，跳出这次枚举 
            
            int target = -nums[i];//x+y=0 -> x = -y
            int l = i + 1, r = n - 1;
            while(l < r)//思路与两数之和相同 
            {
                int sum = nums[l] + nums[r];

                if(sum == target)
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;

                    while(l < r && nums[l - 1] == nums[l]) l++;//在和固定的情况下，要是某个数相同，那么另一个数也会是相同的 
                    while(l < r && nums[r + 1] == nums[r]) r--;
                }
                else if(sum < target) l++;
                else r--;
            }
        }

        return v;
    }
};

//[-1,0,1,2,-1,-4]
//
//[[-1,-1,2],[-1,0,1]]
//
//
//[0,1,1]
//
//[] 
//
//
//[0,0,0]
//
//[[0,0,0]]
