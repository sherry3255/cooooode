/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> a;
    int find(int x){
        return a.count(x)? a[x] = find(a[x]):x;
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto i:nums){
            a[i] = i+1;
        }
        int ans = 0;
        for(auto i :nums){
            int y = find(i+1);
            ans = max(ans,y-i);
        }
        return ans;

    }
    
};
// 上面的答案实在是看不懂了，另一个解题思路是
/*
用 unordered_map 相当于排序，省去了排序的多余的 log(n)时间复杂度；
这样排完序连续的序列只用遍历最小的就可以了；
倒着遍历是因为每次计算 size() 也会耗费一点时间，虽然很少，但是肯定没有直接用变量快吧。

int longestConsecutive(vector<int>& nums) { 
    unordered_map<int,int> a; 
    for(auto i:nums) a[i]=i; 
    int ans=0; 
    for(int i=nums.size()-1;i>=0;--i){      
        if(!a.count(nums[i]-1)){ 找到最小的数，如果不连续，那长度为1.
            int cur=nums[i]; // 记录当前的值
            while(a.count(cur+1)){ 
                ++cur; 
            } 
            ans=max(ans,cur-nums[i]+1); 
        } 
    } 
    return ans; 
}


*/
// @lc code=end

