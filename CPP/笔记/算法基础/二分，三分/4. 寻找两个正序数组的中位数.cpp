// 首先两个数组nums1,nums2都是升序的，如果直接从nums1中二分枚举值，然后根据值去nums2中查找下标，会出现bug，即假如有多个重复
// 的数，那么二分查找的下标就不准确。所以通过二分枚举下标，题目要求中位数，那么一定是下标为中间的数，设nums1中下标为i，nums2中
// 下标为j，那么i+1 + j+1 ==k(k为数字个数)，下标+1即个数，因为base-0。
// 将元素分为左右半区，若个数为奇数，则取左边区最大值，否则取左半区最大值与右半区最小值平均值。肯定存在某个位置是ans，此时
// 该位置有什么特征呢？即nums1[i] <= nums2[j + 1] && nums2[j] <= nums1[i + 1]，概括的说，就是左半区<=右半区，答案就在
// 这四个值中产生。

// 1.若n>m，那么k=(n+m+1)/2，j=k-i-2，i的范围为[0,n-1]，如果i很大或者很小，j就可能超出范围，所以确保n<=m
// 2.假如n=4,m=5，那么k=(4+5+1)/2=5，即左半区要分到5个数，右半区四个；假如n=5,m=5m，k=(5+5+1)/2=5，即左半区要分到5个数，
//   右半区5个。通过向上取整设计k，确保左半区的数>=右半区的数。
// 3.为什么-2？因为base-0，i，j是下标，i+1,j+1才是个数，i+1 + j+1 == k，所以j=k-i-2。
// 4.这种二分的写法确保结束以后r==l+1，出去以后nums1[l]<nums2[j+1]且此时l==i，那么r==i+1，
//   由else可以得到nums1[r]>nums2[j'+1]，这里之所以是j'，因为r==i+1，总数不变的情况下i多了1，j就会少1，即j'==j-1；
//   于是由else得到nums1[i+1]>nums2[j]，第二个条件也满足，左半区<=右半区成立。
// 5.i可能为-1，意味着左半区没有任何数，于是人为插入一个INT_MIN，方便判断；之后的INT_MAX同理。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1); // 1.一定要找短的数组
        int k = (n + m + 1) >> 1; // 2.为什么向上取整

        int l = -1, r = n;
        while(l + 1 != r)
        {
            int i = (l + r) >> 1;
            int j = k - i - 2; // 3.为什么-2

            if(nums1[i] <= nums2[j + 1]) l = i; // 4.这里只满足了一个条件，怎么确保nums2[j] <= nums1[i + 1]？
            else r = i;
        }

        int i = l, j = k - i - 2;
        int li = i >= 0 ? nums1[i] : INT_MIN; // 5.为什么要取INT_MIN？
        int lj = j >= 0 ? nums2[j] : INT_MIN;
        int ri = i + 1 < n ? nums1[i + 1] : INT_MAX;
        int rj = j + 1 < m ? nums2[j + 1] : INT_MAX;

        int mx = max(li, lj);
        int mi = min(ri, rj);
        
        return (m + n) % 2 ? mx : (mx + mi) / 2.;
    }
};

// 示例 1：
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2


// 示例 2：
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5