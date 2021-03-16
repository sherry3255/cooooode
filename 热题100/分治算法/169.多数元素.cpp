/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (65.20%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    268.7K
 * Total Submissions: 408.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 * 
 */

// @lc code=start
class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi){
        int count = 0;
        for(int i = lo; i<= hi; ++i){
            if(nums[i] == target) ++count;
        }
        return count;
    }

    int majority_element_rec(vector<int>& nums, int lo, int hi){
        if(lo == hi) return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if(count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2){
            return left_majority;
        }
        if(count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2){
            return left_majority;
        }
        return -1;
    }

public:
    
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
    
// 时间复杂度直接看链接：https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
// 尽管分治算法没有直接分配额外的数组空间，但在递归的过程中使用了额外的栈空间。算法每次将数组从中间分成两部分，所以数组长度变为 1 之前需要进行 O(log⁡n) 次递归，即空间复杂度为 O(log⁡n)。
/*
分治解决错误，另一种
class Solution { 
public: 
    int majorityElement(vector<int>& nums) { 
        sort(nums.begin(), nums.end()); 
        return nums[nums.size() / 2]; 
    } 
};


*/
// @lc code=end

