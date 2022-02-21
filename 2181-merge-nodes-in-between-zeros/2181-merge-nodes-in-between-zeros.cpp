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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *cur = head->next;
        ListNode *ans = nullptr;
        int sum = 0;
        while (cur != nullptr) {
            sum += cur->val;
            if (cur->val == 0) {
                if (ans == nullptr) ans = head;
                else ans = ans->next;
                ans->val = sum;
                sum = 0;
            }
            cur = cur->next;
        }
        ans->next = nullptr;
        return head;
    }
};