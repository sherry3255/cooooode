/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (57.05%)
 * Likes:    799
 * Dislikes: 0
 * Total Accepted:    176.4K
 * Total Submissions: 306.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
// 单指针的方法
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0;i < n;i++){
            if(nums[i]==0){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
        for(int i = ptr; i<n; i++){
            if(nums[i]==1){
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    }
};

// 双指针的方法
/*
void sortColors(vector<int>& nums){
    int n = nums.size();
    int p0 = 0, p2 = n-1;
    for(int i = 0;i < p2;i++){
        while(i<=p2 && nums[i] == 2){
            swap(nums[i], nums[p2]);
            p2--;
        }
        if(nums[i] = 0){
            swap(nums[i], nums[p0]);
            p0++;
        }
    }
}

间复杂度：O(n)，其中 n 是数组 nums 的长度。
空间复杂度：O(1)。

*/
// @lc code=end

{

}