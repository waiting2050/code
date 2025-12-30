// 这道题用两次二分，第一次找到最小元素下标，第二次定位target。
// 为什么第一次二分？因为数组具有二段性，即左边元素都满足nums[mid]>nums.back()，右边都不满足

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = -1, r = n - 1;
        while(l + 1 != r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums.back()) r = mid;
            else l = mid;
        }

        int idx = r;
        if(nums.back() >= target) l = idx - 1, r = n;
        else l = -1, r = idx;
        
        while(l + 1 != r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target) l = mid;
            else r = mid;
        }
        
        return l >= 0 && nums[l] == target ? l : -1;
    }
};

// 示例 1：
// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4


// 示例 2：
// 输入：nums = [4,5,6,7,0,1,2], target = 3
// 输出：-1


// 示例 3：
// 输入：nums = [1], target = 0
// 输出：-1