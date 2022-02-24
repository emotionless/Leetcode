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
    
    ListNode* getMid(ListNode *st, ListNode *ed) {
        if (st == ed) return st;
        ListNode *slow = st;
        ListNode *fast = st->next;
        while (fast != ed) {
            slow = slow->next;
            fast = fast->next;
            if (fast == ed) break;
            fast = fast->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *ans = nullptr;
        ListNode *cur = nullptr;
        while (left || right) {
            if (left && right) {
                if (left->val < right->val) {
                    if (cur == nullptr) {
                        cur = left;
                        ans = cur;
                        left = left -> next;
                        continue;
                    }
                    cur -> next = left;
                    cur = cur->next;
                    left = left->next;
                } else {
                    if (cur == nullptr) {
                        cur = right;
                        ans = cur;
                        right = right -> next;
                        continue;
                    }
                    cur -> next = right;
                    cur = cur->next;                
                    right = right->next;
                }
            } else if (left) {
                if (cur == nullptr) {
                    cur = left;
                    ans = cur;
                    left = left -> next;
                    continue;
                }
                cur -> next = left;
                cur = cur->next;
                left = left->next;
            } else {
                if (cur == nullptr) {
                    cur = right;
                    ans = cur;
                    right = right -> next;
                    continue;
                }
                cur -> next = right;
                cur = cur->next;
                right = right->next;
            }
        }
        cur->next = nullptr;
        return ans;
    }
    
    ListNode* divide(ListNode *st, ListNode *ed) {
        if (st == nullptr) return nullptr;
        if (st->next == ed) {
            st->next = nullptr;
            return st;
        }
        ListNode *mid = getMid(st, ed);
        ListNode *left = divide(st, mid);
        ListNode *right = divide(mid, ed);
        ListNode *ret = merge(left, right);
        
        return ret;
    }
    
    
    ListNode* sortList(ListNode* head) {
        return divide(head, nullptr);
    }
};