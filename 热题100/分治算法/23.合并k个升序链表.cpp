/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (53.84%)
 * Likes:    1168
 * Dislikes: 0
 * Total Accepted:    216.9K
 * Total Submissions: 399K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 此题用分治算法
class Solution {
public:

    ListNode* mergeTwoLists(ListNode *a,ListNode *b){
        if((!a)||(!b)) return a?a:b;
        ListNode head,*tail = &head, *aPtr = a,*bPtr = b;
        while(aPtr && bPtr){
            if(aPtr->val < bPtr->val){
                tail->next = aPtr;
                aPtr = aPtr->next;
            }else{
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r){
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (r + l) >> 1;
        return mergeTwoLists(merge(lists, l, mid),merge(lists, mid + 1, r));

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);

    }
    
};
// 时间复杂度：加乘计算每一轮合并，为个数乘以长度，O(kn×logk)，空间复杂度：递归会使用到 O(log⁡k) 空间代价的栈空间
// @lc code=end

