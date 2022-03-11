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
    
    int getSize(ListNode *cur) {
        if (cur == nullptr) return 0;
        return 1 + getSize(cur->next);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *right = head;
        int sz = getSize(head);
        if (sz <= 1 || k%sz == 0) return head;
        k--;
        k %= sz;
        int cnt = 0;
        ListNode *prev = nullptr;
        while (cnt < k) {
            cnt++;
            right = right->next;
        }
        ListNode *left = head;
        while (right->next != nullptr) {
            right = right->next;
            prev = left;
            left = left->next;
        }
        right->next = head;
        ListNode *newHead = left;
        prev->next = nullptr;
        return newHead;
    }
};