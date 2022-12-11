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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = head;
        if (head == nullptr) return head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            if (odd->next != nullptr)
                odd = odd->next;
            even->next = odd->next;
            if (even->next != nullptr)
                even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};