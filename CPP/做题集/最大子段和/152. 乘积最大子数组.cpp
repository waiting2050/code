//��֮ǰ��ӷ�������Ӷκ͵�˼����һ���ģ������ﲻ������0�������ˣ���Ϊһ������*һ������Ҳ����ֱ�ӱ��max
//�������ʱ�򲻽���Ҫmax����Ҫmin������ֵ��Ķ��г�Ϊ����max��Ǳ������Ȼ��ͺͳ�������Ӷκ�һ���ˣ��ж��������½���������ͺ� 

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
            mi = min({tmx * nums[i], mi * nums[i], nums[i]}); //ע�����ʱ��mx�Ѿ������� 
            ans = max(ans, mx);
            //cout << ans << ' ' << mx << ' ' << mi << '\n';
        }

        return ans;
    }
};

//����:nums=[2,3,-2,4]
//���:6
//
//
//����: nums = [-2,0,-1]
//���: 0
