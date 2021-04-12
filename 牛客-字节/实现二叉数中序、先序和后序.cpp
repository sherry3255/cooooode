/**
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void preorder(TreeNode* root){
        if(root != nullptr){
            pre.push_back(root -> val);
            preorder(root -> left);
            preorder(root -> right);
        }
    }
 
    void inorder(TreeNode* root){
        if(root != nullptr){
            inorder(root -> left);
            in.push_back(root -> val);
            inorder(root -> right);
        }
    }
 
    void postorder(TreeNode* root){
        if(root != nullptr){
            postorder(root -> left);
            postorder(root -> right);
            post.push_back(root -> val);
        }
    }
 
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        preorder(root);
        res.push_back(pre);
        inorder(root);
        res.push_back(in);
        postorder(root);
        res.push_back(post);
        return res;
    }
private:
    vector<int> pre;
    vector<int> in;
    vector<int> post;
};