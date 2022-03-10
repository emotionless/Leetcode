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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = l1;
        int carry = (l1->val + l2->val)/10;
        cur->val = (l1->val + l2->val)%10;
        l1=l1->next;
        l2=l2->next;
        ListNode *ans = cur;
        while (l1 || l2) {
            int now = carry;
            if (l1) {
                now += l1->val;
            }
            if (l2) {
                now += l2->val;
            }
            if (l1) {
                cur->next = l1;
            } else {
                cur->next = l2;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            cur = cur->next;
            cur->val = now%10;
            carry = now/10;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        
        return ans;
    }
};