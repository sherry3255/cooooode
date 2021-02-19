#include <vector>
using namespace std;

class Solution {
public:
    int result = 0;
    /* 主函数 */
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0) return 0;
        backtrack(nums, 0, S);
        return result;
    }
    /* 回溯算法模板 */
    void backtrack(vector<int>& nums, int i, int rest) {
        // base case
        if (i == nums.size()) {
            if (rest == 0) {
                // 说明恰好凑出 target
                result++;
            }
            return;
        }
        // 给 nums[i] 选择 - 号
        rest += nums[i];
        // 穷举 nums[i + 1]
        backtrack(nums, i + 1, rest);
        // 撤销选择
        rest -= nums[i]; 

        // 给 nums[i] 选择 + 号
        rest -= nums[i];
        // 穷举 nums[i + 1]
        backtrack(nums, i + 1, rest);
        // 撤销选择
        rest += nums[i];
    }

};

// 这个回溯算法本质是一个二叉数的遍历问题，所以时间复杂度为O(2^N)，N 为 nums 的大小
// 是非常低效的做法，在力扣中提交超时。




