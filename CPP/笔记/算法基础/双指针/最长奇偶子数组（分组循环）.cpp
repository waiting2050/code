//����ѭ��
//���ѭ�����������֮ǰ��׼����������¼��ʼλ�ã����ͱ�����֮���ͳ�ƹ��������´����ֵ����
//�ڲ�ѭ����������飬�ҳ���һ����Զ���Ľ����� 

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
                i++; //�����Ҫд��forѭ����������[4,10,3],10����������� 
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
