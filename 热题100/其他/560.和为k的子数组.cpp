/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for(int start = 0;start < nums.size();start++){
            int sum = 0;
            for(int end = start;end>=0;end--){
                sum+=nums[end];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};

/*时间复杂度：O(n^2)，其中 n 为数组的长度。枚举子数组开头和结尾需要 O(n^2) 的时间，其中求和需要 O(1) 的时间复杂度，因此总时间复杂度为 O(n^2)。
空间复杂度：O(1)。只需要常数空间存放若干变量。*/
/*
前缀树和哈希表的做法：

class Solution { 
public: 
    int subarraySum(vector<int>& nums, int k) { 
        unordered_map<int, int> mp; 
        mp[0] = 1; 
        int count = 0, pre = 0; 
        for (auto& x:nums) { 
            pre += x; //  前缀和
            //找出值为pre[i] - k的所有前缀和个数,同时也保证了，此处求得的前缀和pre[j]均在[0,i]范围内
            if (mp.find(pre - k) != mp.end()) { 
                count += mp[pre - k]; 
            } 
            mp[pre]++; // 从左往右遍历时更新前缀和个数
        } 
        return count; 
    } 
};

时间复杂度和空间复杂度均为o(n)


*/

// @lc code=end

