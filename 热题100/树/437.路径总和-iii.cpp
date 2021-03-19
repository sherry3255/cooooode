/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
// 对每个节点，有两种情况：1. 在这个节点为根节点的树中找路径，同时以该节点为起始节点 2. 在这个节点的子树中找。因此，我们就可以写出代码，以该节点为起始的路径 + 子树中的路径
public:
    int pathSum(TreeNode* root, int sum) {
        return root? pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }
    int pathSumStartWithRoot(TreeNode* root, int sum){
        if(!root) return 0;
        int count = root->val == sum;
        count += pathSumStartWithRoot(root->left, sum - root->val);
        count += pathSumStartWithRoot(root->right, sum - root->val);
        return count;
    }
};
/*
    时间复杂度：O(nlogn)
    空间复杂的：O(1)

*/
// @lc code=end

