/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = task.size();
        vector<int> vec(26);
        for(char c: tasks) ++vec[c-'A'];
        sort(vec.begin(), vec.end(),[](int& x, int& y){return x>y;});
        int cnt = 1;
        while(cnt < vec.size() && vec[cnt] == vec[0]){
            cnt++;// 获得最后一个桶中的任务数，这个由与最大任务数的任务并行的任务多少决定
        }
        return max(len,cnt+(vec[0] - 1)*(n+1));
    }
};
// 时间复杂度 O(nlogn)(主要是sort)，空间复杂度 O(1)
// @lc code=end

