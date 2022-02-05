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


struct CustomCompare
{
    bool operator()(const ListNode *lhs, const ListNode *rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        priority_queue<ListNode*, vector<ListNode*>, CustomCompare> container;
        ListNode *ans = NULL;
        for(auto node : lists) {
            if (node != NULL)
                container.push(node);
        }
        ListNode *res = NULL;
        while(!container.empty()) {
            ListNode* top = container.top();
            container.pop();
            if (ans == NULL) {
                ans = top;
                res = ans;
            } else {
                ans -> next = top;
                ans = ans -> next;
            }
            if (top -> next != NULL) {
                container.push(top -> next);
            }
        }
        return res;
    }
};