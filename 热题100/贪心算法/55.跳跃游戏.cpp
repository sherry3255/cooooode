/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;//初始化当前能到达最远的位置
        for(int i = 0;i < nums.size();i++){
            if(i > k) return false; // 当前位置已经大于可到达的最远位置
            // 否则更新可到达的最远位置
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

