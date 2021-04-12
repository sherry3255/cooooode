/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
#include <vector>
#include <stack>
using namespace std;
/*
利用栈的特性，采用两个栈来实现：

    栈1，存放偶数层节点
    栈2，存放奇数层节点 

栈1出栈的时候，将下一层节点push到栈2，这样就实现了不断反转的效果。

有一个至关重要的细节：对栈2出栈并将下一层节点推入栈1的过程中，需要先入右节点再入左节点，否则无法保证顺序。这个特性可以借助例子推导一下。
*/
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // write code here
        vector<vector<int> > res;
        if (!root) return res;
        stack<TreeNode *> stk1, stk2; // stk1存储偶数层,从左到右遍历，stk2存储奇数层，从右到左遍历
        stk1.push(root);
        while (!stk1.empty() || !stk2.empty()) {
            vector<int> vec;
            while (!stk1.empty()) {
                TreeNode *node = stk1.top();
                stk1.pop();
                vec.push_back(node->val);
                if (node->left) stk2.push(node->left);
                if (node->right) stk2.push(node->right);
            }
            if (vec.size() > 0) res.push_back(vec);
            vec.clear();
            while (!stk2.empty()) {
                TreeNode *node = stk2.top();
                stk2.pop();
                vec.push_back(node->val);
                // 偶数层：先入右再入左
                if (node->right) stk1.push(node->right);
                if (node->left) stk1.push(node->left);
            }
            if (vec.size() > 0) res.push_back(vec);
        }
        return res;
    }
};