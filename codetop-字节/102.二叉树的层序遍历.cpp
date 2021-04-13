/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> t;
        t.push(root);
        while(!t.empty()){
            int n = t.size();
            ret.push_back(vector<int>());
            for(int i = 1; i<=n; i++){
                auto node = t.front();
                t.pop();
                ret.back().push_back(node->val);
                if(node->left) t.push(node->left);
                if(node->right) t.push(node->right);
            }
        }
        return ret;
    }
};
// @lc code=end

