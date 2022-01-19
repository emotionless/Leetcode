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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == nullptr) return nullptr;
        if (slow != fast) return nullptr;
        
        // cout << slow->val << endl;
        slow = slow->next;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
            // cout << head->val << " " << slow->val << endl;
        }
        return head;
    }
};