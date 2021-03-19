/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p,q);
        return ans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if((lson && rson) || ((root->val == q->val || root->val == p->val) && (lson || rson))){
            ans = root;
        }
        return lson || rson || (root->val == q->val || root->val == p->val);
    }
};
// @lc code=end

