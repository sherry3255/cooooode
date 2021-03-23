/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int res = x^y;
        while(res!=0){
            if(res%2==1){
                count++;
            }
            res=res>>1;
        }
        return count;
    }
};
// @lc code=end

