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
    ListNode* middleNode(ListNode* head) {
        ListNode *tortoise = head;
        ListNode *hare = head->next;
        if (hare == nullptr) return tortoise;
        while (hare->next != nullptr && hare->next->next != nullptr) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        return tortoise->next;
    }
};