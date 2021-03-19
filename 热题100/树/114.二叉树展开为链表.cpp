/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        vector<TreeNode*> list;
        preorderTraversal(root, list);
        int n = list.size();
        for(int i = 1;i<n;i++){
            TreeNode* pre = list.at(i-1), *cur = list.at(i);
            pre->left = nullptr;
            pre->right = cur;
        }
    }
    void preorderTraversal(TreeNode* root, vector<TreeNode*> &list){
        if(root != nullptr){
            list.push_back(root);
            preorderTraversal(root->left, list);
            preorderTraversal(root->right, list);
        }
    }
};/*
时间复杂度：O(n)，其中 n 是二叉树的节点数。前序遍历的时间复杂度是 O(n)，前序遍历之后，需要对每个节点更新左右子节点的信息，时间复杂度也是 O(n)。

空间复杂度：O(n)，其中 n 是二叉树的节点数。空间复杂度取决于栈（递归调用栈或者迭代中显性使用的栈）和存储前序遍历结果的列表的大小，栈内的元素个数不会超过 n，前序遍历列表中的元素个数是 n。
*/
// @lc code=end

