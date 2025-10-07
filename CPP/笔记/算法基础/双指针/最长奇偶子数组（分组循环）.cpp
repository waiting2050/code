//分组循环
//外层循环负责遍历组之前的准备工作（记录开始位置），和遍历组之后的统计工作（更新答案最大值）。
//内层循环负责遍历组，找出这一组最远在哪结束。 

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        nums.insert(nums.begin(), 0);
        int n = nums.size() - 1;

        int ans = 0;
        for(int i = 1; i <= n;)
        {
            if(nums[i] > threshold || nums[i] & 1)
            {
                i++; //这个不要写到for循环里，否则比如[4,10,3],10这种样例会错 
                continue;
            }

            int st = i;
            for(i++; i <= n; i++)
            {
                if(nums[i] <= threshold && (nums[i] & 1) != (nums[i - 1] & 1) && i <= n) continue;
                break;
            } 
            cout << i << ' ' << st << '\n';
            ans = max(ans, i - st);
        }

        return ans;
    }
};
