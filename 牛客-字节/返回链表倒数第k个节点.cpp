/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* head, int n) {
        // write code here
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=nullptr&&n-->0){
            fast = fast->next;
        }
        if(n>0){
            return nullptr;
        }
        while(fast!= nullptr){
            
            fast = fast->next;
            slow = slow->next;
        }
        return slow;

    }
};