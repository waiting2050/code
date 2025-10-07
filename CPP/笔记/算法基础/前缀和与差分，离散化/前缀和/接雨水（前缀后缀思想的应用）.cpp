
//思路：对于每一个横坐标所对应的y（也就是能接雨水的最大值），分别取左右两侧挡板最高的为lmax,rmax，
//具体能接多少水又取决于min{lmax,rmax)，类似模板效应。所以可以用前缀，后缀的思想去预处理取得lmax,rmax再处理 

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
