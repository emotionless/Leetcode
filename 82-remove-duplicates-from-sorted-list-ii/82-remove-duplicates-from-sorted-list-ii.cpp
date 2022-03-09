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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *cur = head;
        ListNode *ans = nullptr;
        ListNode *first = nullptr;
        while (cur != nullptr) {
            int cnt = 0;
            ListNode *tmp = cur;
            while (tmp != nullptr && cur->val == tmp->val) {
                cnt++;
                tmp = tmp->next;
            }
            if (cnt == 1) {
                if (first == nullptr) {
                    first = cur;
                    ans = cur;
                } else {
                    ans->next = cur;
                    ans = ans->next;
                }
            }
            cur = tmp;
        }
        if (ans) {
            ans->next = nullptr;
        }
        return first;
    }
};