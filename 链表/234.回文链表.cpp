/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (45.11%)
 * Likes:    862
 * Dislikes: 0
 * Total Accepted:    196.8K
 * Total Submissions: 432.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
// 快慢指针的做法
class Solution {
public:

    bool isPalindrome(ListNode* head) {
        ListNode slow, fast;
        slow = fast = head;
        while(fast != NULL && fast.next != NULL){
            slow = slow.next;
            fast = fast.next.next;
        }
        if(fast!= NULL) slow = slow.next;
        ListNode left = head;
        ListNode right = reverse(slow);

        while(right!= NULL){
            if(left.val!=right.val)
            {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        return true;
    }
    
    ListNode reverse(ListNode head){
        ListNode pre = NULL;
        ListNode cur = head;
        ListNode nxt = head;
        while(cur!= NULL){
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end

