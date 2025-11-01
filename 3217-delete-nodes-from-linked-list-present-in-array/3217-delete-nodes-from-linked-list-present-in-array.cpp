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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *root = NULL;
        ListNode *last = NULL;
        unordered_set<int> contagious;
        for (auto &num : nums) {
            contagious.insert(num);
        }
        ListNode *cur = head;
        while (cur != NULL) {
            int val  = cur->val;
            if (contagious.find(val) == contagious.end()) {
                if (root == NULL) {
                    root = cur;
                    last = cur;
                } else {
                    last->next = cur;
                    last = cur;
                }
            }
            cur = cur->next;
        }
        if (last != NULL)
            last->next = NULL;
        return root;
    }
};