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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *ans = head->next;
        ListNode *pre = nullptr;
        while (head) {
            ListNode *next = head->next;
            if (next == nullptr) {
                pre->next = head;
                break;
            }
            ListNode *farNext = next->next;
            next->next = head;
            if (pre) pre->next = next;
            head->next = nullptr;
            pre = head;
            head = farNext;
        }
        return ans;
    }
};