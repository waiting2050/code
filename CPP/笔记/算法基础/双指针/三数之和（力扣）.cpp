
//˼·������Ҫ����ǰ�õ�����֮����Ŀ����һ���������飨������������ָ��ȥ���ƺ͵Ĵ�С�����Ӷ�O(n)��
//��ô����֮�Ϳ���ת��Ϊ����ö�����i��Ȼ����취������֮�͵���-nums[i]�����Ӷ�O(n^2)��
//������Ŀ��Ҫ�����ظ����ⲿ��ע�ͻ��ڴ�����չʾ�� 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
	{
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> v;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i - 1] == nums[i]) continue;//ȥ�ء������һ��������ͬ���������ճ���һ�����ķ���Ҳ������ͬ�ġ� 
            //����С�Ż� 
			if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;//��С����������������0����ô�����ֻ����� 
            if(nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;//�����ǰ����������������С��0����ô�м���������������Ǵ𰸣��������ö�� 
            
            int target = -nums[i];//x+y=0 -> x = -y
            int l = i + 1, r = n - 1;
            while(l < r)//˼·������֮����ͬ 
            {
                int sum = nums[l] + nums[r];

                if(sum == target)
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;

                    while(l < r && nums[l - 1] == nums[l]) l++;//�ں͹̶�������£�Ҫ��ĳ������ͬ����ô��һ����Ҳ������ͬ�� 
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
