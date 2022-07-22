/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = NULL, *right = NULL, *cur = head, *start = NULL, *start_right = NULL;
        while(cur != NULL) {
            if(cur -> val < x) {
                if (left == NULL) { 
                    left = cur;
                    start = cur;
                } else {
                    left -> next = cur;
                    left = left -> next;
                }
            } else {
                if (right == NULL) { 
                    right = cur;
                    start_right = cur;
                } else {
                    right -> next = cur;
                    right = right -> next;
                }
            }
            cur = cur -> next;
        }
        if (start == NULL) return head;
        left -> next = start_right;
        if (right) right -> next = NULL;
        return start;
    }
};