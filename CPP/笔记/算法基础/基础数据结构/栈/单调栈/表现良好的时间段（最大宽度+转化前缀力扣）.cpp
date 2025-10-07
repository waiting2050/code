
//思路：对超过8小时的记作1，否则记作-1，计算前缀和pre。
//形式化的，i < j,pre[i] > pre[j]则符合题意。这个时候问题就转化为了之前找最大宽度的问题。 

class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        hours.insert(hours.begin(), 0);
        int n = hours.size() - 1;
        vector<int> stk(n + 1), pre(n + 1);

        for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (hours[i] > 8 ? 1 : -1);
        int top = 0;
        for(int i = 1; i <= n; i++)
            if(!top || pre[i] < pre[stk[top]]) stk[++top] = i;
        
        int ans = 0;
        for(int i = n; i >= ans; i--)
        {
            if(pre[i] > 0) ans = max(ans, i);//这里需要特判
			//虽然数组下标范围是[1,n]，但是左端点可以取到0(前缀和的特殊之处)。 
            while(top && pre[i] > pre[stk[top]])
            {
                ans = max(ans, i - stk[top]);
                top--;
            }
        }

        return ans;
    }
};
