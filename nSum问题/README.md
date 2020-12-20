# 算法模板

'''
    vector<vector<int> > twoSum(vector<int>& nums,int target){
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int lo = 0;
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
'''

sort排序的复杂度为O(NlogN),2sum问题双指针操作时间复杂度为O(N)。