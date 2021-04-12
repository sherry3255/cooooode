class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int>& nums) {
        int x = 0, votes = 0, count = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 验证 x 是否为众数
        for(int num : nums)
            if(num == x) count++;
        return count > nums.size() / 2 ? x : 0; // 当无众数时返回 0
    }
};