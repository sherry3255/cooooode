/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
// 单链表节点的结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x),next(next){}
};

class Solution {
public:



    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if(m == 1){
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m-1, n-1);
    }

    ListNode* reverseN(ListNode* head, int n){

        ListNode* successor = nullptr;
        if (n == 1) { 
            // 记录第 n + 1 个节点
            successor = head->next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode* last = reverseN(head->next, n - 1);

        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;
        return last;
    }
};
// @lc code=end

