# 算法模板

2Sum问题模板：

```
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
```

sort排序的复杂度为O(NlogN),2sum问题双指针操作时间复杂度为O(N)。
nSum问题归总模板，nSum问题即nSum套n-1Sum套n-2Sum套n-3Sum……
3Sum时间复杂度O(N^2),4Sum问题O(N^3)……

```
/* 注意：调用这个函数之前一定要先给 nums 排序 */
vector<vector<int>> nSumTarget(
    vector<int>& nums, int n, int start, int target) {

    int sz = nums.size();
    vector<vector<int>> res;
    // 至少是 2Sum，且数组大小不应该小于 n
    if (n < 2 || sz < n) return res;
    // 2Sum 是 base case
    if (n == 2) {
        // 双指针那一套操作
        int lo = start, hi = sz - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
    } else {
        // n > 2 时，递归计算 (n-1)Sum 的结果
        for (int i = start; i < sz; i++) {
            vector<vector<int>> 
                sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
            for (vector<int>& arr : sub) {
                // (n-1)Sum 加上 nums[i] 就是 nSum
                arr.push_back(nums[i]);
                res.push_back(arr);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    return res;
}
```