/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isExist(TreeNode* cur, int num, int b) {
        if (b < 0) return true;
        bool d = (num&(1<<b));
        if (d == 0) {
            if (cur -> left == NULL) return false;
            return isExist(cur -> left, num, b - 1);
        } else {
            if (cur -> right == NULL) return false;
            return isExist(cur -> right, num, b - 1);
        }
    }
    
    int numberOfBits(int s) {
        int c = 0;
        while(s) {
            s = s / 2;
            c++;
        }
        return c;
    }
    
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int st = 1, ed = INT_MAX;
        int ans = -1;
        while(st <= ed) {
            int mid = st / 2 + ed / 2;
            if (st%2 == ed %2 && st&1) mid++;
            int b = log2(mid) + 1;
            if (isExist(root, mid, b - 2)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
};