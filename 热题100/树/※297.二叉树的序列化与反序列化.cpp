/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec { 
public: 
// Encodes a tree to a single string. 
    string serialize(TreeNode* root) { 
        if (!root) { 
            return ""; 
        } 
        string res; 
        queue<TreeNode*> q{{root}}; 
        while (!q.empty()) { 
            auto cur = q.front(); q.pop(); 
            if (cur) { 
                res += to_string(cur->val) + ","; 
                q.push(cur->left); 
                // Note: this has no condition check cur->left null or not 
                q.push(cur->right); 
                // Note: this has no condition check cur->right null or not 
            } else { 
                res += "#,"; 
            }            
        } return res; 
    } // Decodes your encoded data to tree. 
    TreeNode* deserialize(string data) { 
        cout << data << endl; 
        if (data.empty()) { 
            return nullptr; 
        } 
        stringstream ss(data); 
        string str; 
        getline(ss, str, ','); 
        TreeNode* root = new TreeNode(stoi(str)); 
        queue<TreeNode*> q{{root}}; 
        while (!q.empty()) { 
            auto cur = q.front(); q.pop(); 
            if (!getline(ss, str, ',')) { 
                break; 
                // run of data 
            } 
            if (str != "#") { 
                cur->left = new TreeNode(stoi(str)); 
                q.push(cur->left); 
            } else { 
                cur->left = nullptr; 
            } 
            if (!getline(ss, str, ',')) { 
                break; 
                // run of data 
            } 
            if (str != "#") { 
                cur->right = new TreeNode(stoi(str)); 
                q.push(cur->right); 
            } else { 
                cur->right = nullptr; 
            } 
        } 
        return root; 
    } 
}; 

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

 