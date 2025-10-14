class Solution 
{
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int mid = l + rand() % (r - l + 1);
        int mv = nums[mid];
        swap(nums[l], nums[mid]);

        int i = l + 1, j = r;
        while(true)
        {
            while(i <= j && nums[i] < mv) i++;
            while(i <= j && nums[j] > mv) j--;

            if(i >= j) break;

            swap(nums[i], nums[j]);
            i++, j--;
        }
        swap(nums[l], nums[j]);

        return j;
    }

    void quickSort(vector<int>& nums, int l, int r)
    {
        // STL 写法：is_sorted(nums.begin() + left, nums.begin() + right + 1)
        bool flag = true;
        for(int i = l; i < r; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                flag = false;
                break;
            }
        }

        if(flag) return;

        int i = partition(nums, l, r);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        srand(time(0));
        int n = nums.size();
        quickSort(nums, 0, n - 1);

        return nums;
    }
};

// 示例 1：
// 输入：nums = [5,2,3,1]
// 输出：[1,2,3,5]
// 解释：数组排序后，某些数字的位置没有改变（例如，2 和 3），而其他数字的位置发生了改变（例如，1 和 5）。


// 示例 2：
// 输入：nums = [5,1,1,2,0,0]
// 输出：[0,0,1,1,2,5]
// 解释：请注意，nums 的值不一定唯一。