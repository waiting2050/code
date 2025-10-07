
//˼·������ÿһ������������Ӧ��y��Ҳ�����ܽ���ˮ�����ֵ�����ֱ�ȡ�������൲����ߵ�Ϊlmax,rmax��
//�����ܽӶ���ˮ��ȡ����min{lmax,rmax)������ģ��ЧӦ�����Կ�����ǰ׺����׺��˼��ȥԤ����ȡ��lmax,rmax�ٴ��� 

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size() - 1;
        vector<int> pre(n + 1), suf(n + 1);

        pre[0] = height[0], suf[n] = height[n];
        for(int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], height[i]);
        for(int i = n - 1; i > 0; i--) suf[i] = max(suf[i + 1], height[i]);

        int ans = 0;
        for(int i = 1; i < n; i++) ans += max(min(pre[i], suf[i]) - height[i], 0);

        return ans;
    }
};
