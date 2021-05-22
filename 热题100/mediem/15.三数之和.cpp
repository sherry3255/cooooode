/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
/*class Solution {
public:
    vector<vector<int> > twoSum(vector<int>& nums,int start,int target){
        //sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int lo = start;
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
    vector<vector<int> > threeSum(vector<int>& nums,int target=0){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<vector<int>> tuples = twoSum(nums,i+1,target-nums[i]);
            for(vector<int>& tuple:tuples){
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i<n-1&&nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};
// @lc code=end

3Sum 问题就解决了，时间复杂度不难算，排序的复杂度为 O(NlogN).
twoSumTarget 函数中的双指针操作为 O(N)，
threeSumTarget 函数在 for 循环中调用 twoSumTarget 所以总的时间复杂度就是 O(NlogN + N^2) = O(N^2)。

以上回答在力扣中超出了时间限制。
*/
/* 我们枚举的三元组 (a,b,c)(a, b, c)(a,b,c) 满足 a≤b≤c，保证了只有 (a,b,c)，而 (b,a,c)(c,b,a) 等等这些不会，这样就减少了重复。
如果我们固定了前两重循环枚举到的元素 a 和 b，那么只有唯一的 c 满足 a+b+c=0。
当第二重循环往后枚举一个元素 b′ 时，由于 b′>b，那么满足 a+b′+c′=0的 c′一定有 c′<c，即 c′在数组中一定出现在 c的左侧。
也就是说，我们可以从小到大枚举 b，同时从大到小枚举 c，即第二重循环和第三重循环实际上是并列的关系。

当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法，
将枚举的时间复杂度从 O(N^2) 减少至 O(N)。因为在枚举的过程每一步中，「左指针」会向右移动一个位置（也就是题目中的 bbb），
而「右指针」会向左移动若干个位置，这个与数组的元素有关，但我们知道它一共会移动的位置数为 O(N)，均摊下来，每次也向左移动一个位置，
因此时间复杂度为 O(N)。

注意到我们的伪代码中还有第一重循环，时间复杂度为 O(N)，因此枚举的总时间复杂度为 O(N^2)。
由于排序的时间复杂度为 O(Nlog⁡N)，在渐进意义下小于前者，因此算法的总时间复杂度为 O(N^2)。

上述的伪代码中还有一些细节需要补充，例如我们需要保持左指针一直在右指针的左侧（即满足 b≤c）
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        // 枚举a
        for(int a = 0;a<n;a++){
            // a和上一次枚举的不同
            if(a>0 && nums[a] == nums[a-1]){
                continue;
            }
            int c = n-1;
            int target = -nums[a];
            // 枚举b
            for(int b = a+1;b<n;b++){
                if(b>a+1 && nums[b]==nums[b-1]){
                    continue;
                }
                while(b<c && nums[b]+nums[c] > target){
                    c--;
                }
                if(b == c) break;
                if(nums[b] + nums[c] == target){
                    ans.push_back({nums[a],nums[b],nums[c]});
                }
            }
        }
        return ans;

    }

};



