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
    Solution(ListNode* head) {
        this->head = head;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        // int r = rand() % nums.size();
        // return nums[r];
        int res = head->val;
        ListNode *node = head->next;
        int i = 2;
        while (node != nullptr) {
            int r = rand() % i;
            if (r == 0) {
                res = node->val;
            }
            i++;
            node = node->next;
        }
        return res;
    }
private:
    vector<int> nums;
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */