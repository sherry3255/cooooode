/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (39.31%)
 * Likes:    3733
 * Dislikes: 0
 * Total Accepted:    338.6K
 * Total Submissions: 854.3K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

/*
最直观的思路有以下两种：

    使用归并的方式，合并两个有序数组，得到一个大的有序数组。大的有序数组的中间位置的元素，即为中位数。

    不需要合并两个有序数组，只要找到中位数的位置即可。由于两个数组的长度已知，因此中位数对应的两个数组的下标之和也是已知的。维护两个指针，初始时分别指向两个数组的下标 000 的位置，每次将指向较小值的指针后移一位（如果一个指针已经到达数组末尾，则只需要移动另一个数组的指针），直到到达中位数的位置。

第一种思路的时间复杂度是 O(m+n)，空间复杂度是 O(m+n)。第二种思路虽然可以将空间复杂度降到 O(1)，但是时间复杂度仍是 O(m+n)。

如何把时间复杂度降低到 O(log⁡(m+n))呢？如果对时间复杂度的要求有 log，通常都需要用到二分查找，这道题也可以通过二分查找实现。

根据中位数的定义，当 m+n是奇数时，中位数是两个有序数组中的第 (m+n)/2 个元素，当 m+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2 个元素和第 (m+n)/2+1 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1。
第一种思路的时间复杂度是 O(m+n)，空间复杂度是 O(m+n)。第二种思路虽然可以将空间复杂度降到 O(1)，但是时间复杂度仍是 O(m+n)。

如何把时间复杂度降低到 O(log⁡(m+n)) 呢？如果对时间复杂度的要求有 log，通常都需要用到二分查找，这道题也可以通过二分查找实现。

根据中位数的定义，当 m+n 是奇数时，中位数是两个有序数组中的第 (m+n)/2 个元素，当 m+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2 个元素和第 (m+n)/2+1 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1。

假设两个有序数组分别是 A 和 B。要找到第 k 个元素，我们可以比较 A[k/2−1] 和 B[k/2−1]，其中 / 表示整数除法。由于 A[k/2−1] 和 B[k/2−1] 的前面分别有 A[0 .. k/2−2] 
和 B[0 .. k/2−2]，即 k/2−1 个元素，对于 A[k/2−1] 和 B[k/2−1] 中的较小值，最多只会有 (k/2−1)+(k/2−1)≤k−2 个元素比它小，那么它就不能是第 k 小的数了。

*/
// @lc code=start
class Solution {
public:
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/

    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
    * 这里的 "/" 表示整除
    * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
    * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
    * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
    * 这样 pivot 本身最大也只能是第 k-1 小的元素
    * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
    * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
    * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
    */
    int getkthelement(vector<int>& nums1, vector<int>& nums2,int k)
    {
        int m=nums1.size();
        int n=nums2.size();
        int index1=0;
        int index2=0;
        while(1)
        {
            if(index1==m)
            {
                return nums2[index2+k-1]; // 取倒数nums2倒数第k个数
            }
            if(index2==n)
            {
                return nums1[index1+k-1];
            }
            if(k==1)
            {
                return min(nums1[index1],nums2[index2]);
            }

            int newindex1=min(index1+k/2-1,m-1); //保证新的下标不会越界
            int newindex2=min(index2+k/2-1,n-1);
            if(nums1[newindex1]<=nums2[newindex2])
            {
                k -= newindex1 - index1 + 1; // 减去删除的数的个数
                index1=newindex1+1;// 取新的开头
            }
            else
            {
                k -= newindex2 - index2 + 1;
                index2=newindex2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if(len%2==1)
            return getkthelement(nums1,nums2,(len+1)/2);
        else
            return (getkthelement(nums1,nums2,len/2)+getkthelement(nums1,nums2,len/2+1))/2.0;
    }
};


// @lc code=end

