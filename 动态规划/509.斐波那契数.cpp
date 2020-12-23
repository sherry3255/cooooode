/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// 穷举-->备忘录-->
// 递归解法
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n<1) return 0;
        vector<int> mem(n+1,0);
        return fibFunc(mem,n);
    }
    int fibFunc(vector<int>mem,int n){
        if(n==1||n==2) return 1;
        if(mem[n]!=0) return mem[n];
        mem[n] = fibFunc(mem,n-1)+fibFunc(mem,n-2);
        return mem[n];
    }
};
// @lc code=end

