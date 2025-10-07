
//思路：相向指针，分别指向头尾。这个时候考虑是移动左还是右。考虑面积的贡献是底乘高，底的话移动左右指针都是长度减1，没有区别，
//但是高的话，移动高的指针不如移动矮的指针贡献大。所以可以每次算出面积后，移动矮的指针。 

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
