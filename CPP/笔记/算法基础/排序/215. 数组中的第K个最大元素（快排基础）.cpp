// 时间复杂度o(n)=n+n/2+n/4+...≈2n

class Solution 
{
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int mid = l + rand() % (r - l + 1); // 随机取数，防止o(n^2)
        int mv = nums[mid];      // 比如每次选最左边的（最小），要是数组本身有序，那么将会退化至o(n^2)
        swap(nums[l], nums[mid]); // 将作为基准的元素放在开头，防止每次特判基准元素

        int i = l + 1, j = r;
        while(true) 
        {
            // 答疑：代码中的 nums[i] < pivot 和 nums[i] > pivot 能否改成 nums[i] <= pivot 和 nums[i] >= pivot？
            // 答：这个做法会在子数组所有元素相同时，划分后的 j 是子数组最后一个元素的下标，是最不均匀划分，算法会退化至 O(n²)。
            while(i <= j && nums[i] < mv) i++;
            while(i <= j && nums[j] > mv) j--;
            
            // 答疑：代码中的 i <= j 能否改成 i < j？
            // 答：这会算错。来看一个例子 nums = [2,1,3], pivot = 2。左指针 i = 1 移动到 i = 2，右指针 j = 2 因为不满足 i < j 的条件，无法移动。
            // 此时我们交换 2 和 nums[j] = 3，得到 [3,1,2]，返回 j = 2。然而 j = 2 左侧有大于 pivot = 2 的元素，划分失败。
            // 如果写成 i <= j，那么最终 i = 2，j = 1。此时我们交换 2 和 nums[j] = 1，得到 [1,2,3]，返回 j = 1。这样的划分就是正确的。
            if(i >= j) break;

            swap(nums[i], nums[j]);
            i++, j--;
        }
        // 为什么与 j 交换？
        // 如果与 i 交换，可能会出现 i = right + 1 的情况，已经下标越界了，无法交换
        // 而与 j 交换，即使 j = left，交换也不会出错
        swap(nums[l], nums[j]);
        
        return j; // 返回基准元素下标
    }

    int findKthLargest(vector<int>& nums, int k) 
    {
        srand(time(0));
        int n = nums.size();
        int target = n - k;

        int l = 0, r = n - 1;
        while(true)
        {
            int i = partition(nums, l, r);
            if(i == target) return nums[i];
            else if(i < target) l = i + 1;
            else r = i - 1;
        }
    }
};

// 示例 1:
// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5


// 示例 2:
// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4
