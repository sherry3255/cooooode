/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        stack<int> st;//下标
        for(int i=0;i<T.size();i++){
            while(!st.empty() && T[i] > T[st.top()]){
                auto temp = st.top();
                st.pop();
                res[temp] = i - temp;
            }
            st.push(i);
        }
        return res;
    }
};
// 时间复杂度和空间复杂度都为o(n)
// @lc code=end

