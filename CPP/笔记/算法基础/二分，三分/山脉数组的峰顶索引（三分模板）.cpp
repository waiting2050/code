class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int lm = l + (r - l) / 3;
            int rm = r - (r - l) / 3;
            
            if(arr[lm] < arr[rm]) l = lm + 1;
            else r = rm - 1;
        }

        return l;
    }
};

// 示例 1：
// 输入：arr = [0,1,0]
// 输出：1


// 示例 2：
// 输入：arr = [0,2,1,0]
// 输出：1


// 示例 3：
// 输入：arr = [0,10,5,2]
// 输出：1