#include <vector>
using namespace std;

// 动态规划解法
int fib(int N) {
    if (N < 1) return 0;
    if (N == 1 || N == 2) return 1;
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}

// 进阶空间复杂度压缩：「状态压缩」
int fib(int n) {
    if (n < 1) return 0;
    if (n == 2 || n == 1) 
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}