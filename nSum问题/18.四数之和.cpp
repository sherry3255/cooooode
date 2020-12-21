/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (39.50%)
 * Likes:    697
 * Dislikes: 0
 * Total Accepted:    142.2K
 * Total Submissions: 360.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res = nSumTarget(nums,4,0,target);
        return res;
    }
    vector<vector<int>> nSumTarget(vector<int>& nums,int n,int start,int target){
        vector<vector<int>> res;
        int sz = nums.size();
        if(n<2||sz<n) return res;
        else if(n==2){
            int lo = start,hi = sz-1;            
            while(lo<hi){
                int sum = nums[lo]+nums[hi];
                int left = lo,right = hi;
                if(sum<target){
                    while(lo<hi&&nums[lo]==nums[lo+1]) lo++;
                }else if(sum>target){
                    while(lo<hi&&nums[hi]==nums[hi-1]) hi--;
                }else{
                    res.push_back({left,right});
                    while(lo<hi&&nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi&&nums[hi]==nums[hi-1]) hi--;
                }
            }
        }else{
            for(int i=0;i<sz;i++){
                vector<vector<int>> sumSums = nSumTarget(nums,n-1,i+1,target-nums[i]); 
                for(vector<int> sumSum:sumSums){
                    sumSum.push_back(nums[i]);
                    res.push_back(sumSum);
                }   
                while(i<sz&&nums[i]==nums[i+1]) i++;            
            }
        }
        return res;       
    }
};
// @lc code=end

