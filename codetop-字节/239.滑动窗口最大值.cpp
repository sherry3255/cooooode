/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.00%)
 * Likes:    861
 * Dislikes: 0
 * Total Accepted:    127.2K
 * Total Submissions: 256.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,-1], k = 1
 * 输出：[1,-1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [9,11], k = 2
 * 输出：[11]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [4,-2], k = 2
 * 输出：[4]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> t;
        // 先补全前面k宽的窗口，并获取最大值
        for(int i = 0; i<k; i++){
            // 保证队头是最大值，新的元素小于队头元素
            while(!t.empty() && nums[i] >= nums[t.back()]){
                t.pop_back();
            }
            t.push_back(i);
        }
        vector<int> ans = {nums[t.front()]};
        // 对于后面加入的元素，判断是否比队尾大，以此更新t中的元素
        for(int i = k;i < n; ++i){
            while(!t.empty() && nums[i] >= nums[t.back()]){
                t.pop_back();
            }
            t.push_back(i);
            // 如果最大值的索引超出窗口范围，就将这个最大值弹出
            while(t.front() <= i-k){
                t.pop_front();
            }
            ans.push_back(nums[t.front()]);

        }
        return ans;
    }   
};/*

时间复杂度：O(n)，其中 n 是数组 nums的长度。每一个下标恰好被放入队列一次，并且最多被弹出队列一次，因此时间复杂度为 O(n)。

空间复杂度：O(k)。与方法一不同的是，在方法二中我们使用的数据结构是双向的，因此「不断从队首弹出元素」保证了队列中最多不会有超过 k+1个元素，因此队列使用的空间为 O(k)。

*/
// @lc code=end

