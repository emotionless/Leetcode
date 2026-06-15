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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *tortose = head, *hare = head->next;
        if (hare == nullptr) return nullptr;
        while (hare != nullptr) {
            if (hare->next == nullptr || hare->next->next == nullptr) {
                break;
            }
            hare = hare->next->next;
            tortose = tortose->next;
        }
        tortose->next = tortose->next->next;
        return head;
    }
};