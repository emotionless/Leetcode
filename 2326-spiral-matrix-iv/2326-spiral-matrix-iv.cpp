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
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    void solve(int r, int c, int d, ListNode *head) {
        if (head == nullptr) return;
        ans[r][c] = head->val;
        // cout << d << " " << r << " " << c << endl;
        for (int i = d; i < 8; i++) {
            int ind = i%4;
            int nr = r + dr[ind];
            int nc = c + dc[ind];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || ans[nr][nc] != -1) continue;
            solve(nr, nc, ind, head->next);
            return;
        }
    }
    
    vector<vector<int>> spiralMatrix(int _n, int _m, ListNode* head) {
        n = _n, m = _m;
        ans.resize(n, vector<int>(m, -1));
        solve(0, 0, 0, head);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int n, m;
};