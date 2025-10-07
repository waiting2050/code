
//˼·������ָ�룬�ֱ�ָ��ͷβ�����ʱ�������ƶ������ҡ���������Ĺ����ǵ׳˸ߣ��׵Ļ��ƶ�����ָ�붼�ǳ��ȼ�1��û������
//���ǸߵĻ����ƶ��ߵ�ָ�벻���ƶ�����ָ�빱�״����Կ���ÿ�����������ƶ�����ָ�롣 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size() - 1;
        for(int i = 0, j = n; i < j;)
        {
            int len = j - i;
            int mi = min(height[i], height[j]);
            
            ans = max(ans, len * mi);
            
            if(height[i] == mi) i++;
            else j--;
        }

        return ans;
    }
};
