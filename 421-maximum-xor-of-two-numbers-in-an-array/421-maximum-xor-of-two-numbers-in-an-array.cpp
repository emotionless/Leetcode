class Solution {
public:
    
    struct node {
        bool isEnd;
        node *next[2];
        node() {
            isEnd = false;
            next[0] = next[1] = nullptr;
        }
    };
    
    void insert(node *root, int &num) {
        node *cur = root;
        for (int i = 30; i >= 0; i--) {
            bool id = num&(1<<i);
            if (cur->next[id] == nullptr) {
                cur->next[id] = new node();
            }
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }
    
    int getMaxXor(node *root, int &num) {
        node *cur = root;
        int mul = pow(2.0, 30.0);
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            bool id = num&(1<<i);
            id ^= 1;
            if (cur == nullptr) {
                if (num&(1<<i)) {
                    ans += mul;
                }
                mul /= 2;
                continue;
            }
            if (cur->next[id] == nullptr) {
                cur = cur->next[id^1];
            } else {
                cur = cur->next[id];
                ans += mul;
            }
            mul /= 2;
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        node *root = new node();
        insert(root, nums[0]);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            int ans = getMaxXor(root, num);
            res = max(res, ans);
            insert(root, num);
        }
        return res;
    }
};