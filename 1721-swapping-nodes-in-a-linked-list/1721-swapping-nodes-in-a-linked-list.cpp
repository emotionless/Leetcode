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
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = nullptr, *second = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            k--;
            second = (second == nullptr)? nullptr : second->next;
            if (k == 0) {
                first = cur;
                second = head;
            }
            cur = cur->next;
        }
        swap(first->val, second->val);
        
        return head;
    }
};