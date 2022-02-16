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
    
    ListNode* getNode(ListNode *head, int first) {
        ListNode *cur = head;
        while (first > 1) {
            cur = cur->next;
            first--;
        }
        return cur;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getSize(head);
        ListNode *firstNode = getNode(head, k);
        ListNode *lastNode = getNode(head, n - k + 1);
        swap(firstNode->val, lastNode->val);
        return head;
    }
};