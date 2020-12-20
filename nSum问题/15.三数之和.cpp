/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int> > twoSum(vector<int>& nums,int start,int target){
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int lo = start;
        int hi = nums.size()-1;
        while(lo<hi){
            int sum = nums[lo]+nums[hi];
            int left = nums[lo],right = nums[hi];
            if(sum>target){
                while(lo<hi&&nums[hi]==right) hi--;
            }
            else if(sum<target){
                while(lo<hi&&nums[lo]==left) lo++;
            }
            else{
                res.push_back({left,right});
                while(lo<hi&&nums[lo]==nums[lo+1]) lo++;
                while(lo<hi&&nums[hi]==nums[hi-1]) hi--;
            }
        }
        return res;
    }
    vector<vector<int> > threeSum(vector<int>& nums,int target=0){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<vector<int>> tuples = twoSum(nums,i+1,target-nums[i]);
            for(vector<int>& tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i<n-1&&nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
// @lc code=end

