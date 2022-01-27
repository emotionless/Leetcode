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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse
        ListNode *cur = slow->next;
        slow->next = nullptr;
        ListNode *pre = nullptr;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        
        int ans = 0;
        while (head) {
            ans = max(ans, head->val + pre->val);
            head = head->next;
            pre = pre->next;
        }
        return ans;
    }
};