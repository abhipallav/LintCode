Problem: http://www.lintcode.com/en/problem/reverse-linked-list-ii/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        int count = 1;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(count<m){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        ListNode *start = curr;
        ListNode *prevToStart = prev;
        
        while(count<=n){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(prevToStart==NULL){
            head = prev;
            start->next = curr;
        }else{
            prevToStart->next = prev;
            start->next = curr;
        }
        
        return head;
    }
};
