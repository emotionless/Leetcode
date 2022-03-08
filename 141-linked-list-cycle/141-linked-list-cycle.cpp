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
    bool hasCycle(ListNode *head) {
        ListNode *hare = head;
        if (head == nullptr) return head;
        ListNode *tortoise = head->next;
        while (tortoise != nullptr) {
            if (hare == tortoise) return true;
            hare = hare->next;
            tortoise = tortoise->next;
            if (tortoise)
                tortoise = tortoise->next;
        }
        return false;
    }
};