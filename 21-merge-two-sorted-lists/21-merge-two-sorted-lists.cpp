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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur;
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        if(l1->val < l2->val) {
            cur = l1;
            l1 = l1 -> next;
        }
        else {
            cur = l2;
            l2 = l2 -> next;
        }
        ListNode *ans = cur;
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if(l1 == NULL) cur -> next = l2;
        else if(l2 == NULL) cur -> next = l1;
        
        return ans;
    }
};