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
class Solution {
public:

    ListNode* mergeTwoList(ListNode* l1,ListNode*l2){
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else if(l2->val<l1->val){
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == nullptr? l2:l1;
        return preHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for(size_t i = 0; i < lists.size(); ++i){
            ans = mergeTwoList(ans, lists[i])
        }
        return ans;     
    }
};
/*
时间复杂度：假设每个链表的最长长度是 n。在第一次合并后，ans 的长度为 n；第二次合并后，ans 的长度为 2×n，第 i 次合并后，ans 的长度为 i×n。第 i 次合并的时间代价是 O(n+(i−1)×n)=O(i×n)，那么总的时间代价为 O(∑i=1k(i×n))=O((1+k)⋅k2×n)=O(k2n)，故渐进时间复杂度为 O(k^2 n)。
空间复杂度:没有用到与k和n 规模相关的辅助空间，故渐进空间复杂度为 O(1)。
*/

/* 分治算法在 mergeKLists上有区别
ListNode* merge(vector<ListNode*> &list,int l, int r){
    if(l==r) return lists[l];
    if(l>r) return nullptr;
    int mid = (l + r)>>1;
    return mergeTwoList(merge(lists,l,mid),merge(lists,mid+1,r));
}

ListNode* mergeKLists(vector<ListNode*>& lists){
    return merge(lists,0,lists.size()-1);
}

时间复杂度：考虑递归「向上回升」的过程——第一轮合并 k2\frac{k}{2}2k​ 组链表，每一组的时间代价是 O(2n)；第二轮合并 k/4 组链表，每一组的时间代价是 O(4n)......所以总的时间代价是 O(∑i=1~∞2^k/i×2^i×n)=O(kn×log⁡k)，故渐进时间复杂度为 O(kn×log⁡k)。
空间复杂度：递归会使用到 O(log⁡k)O(\log k)O(logk) 空间代价的栈空间。

*/
// @lc code=end

