class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int x = 1; x < n; ++x)
            children[parent[x]].push_back(x);
        vector<int> size(n, 1), above(n);
        array<int, 26> last;  // last[c]: the deepest node with letter c on the path from the root
        last.fill(-1);
        vector<int> stack{0};  // x enters x, ~x leaves it: no recursion, so no stack overflow on a deep tree
        while (!stack.empty()) {
            int x = stack.back();
            stack.pop_back();
            if (x >= 0) {
                int c = s[x] - 'a';
                above[x] = last[c];  // the closest ancestor with the same letter, or -1
                last[c] = x;
                stack.push_back(~x);  // leave x after all its children
                stack.insert(stack.end(), children[x].begin(), children[x].end());
            } else {
                x = ~x;
                last[s[x] - 'a'] = above[x];
                if (x)  // the root has no parent
                    size[above[x] >= 0 ? above[x] : parent[x]] += size[x];
            }
        }
        return size;
    }
};

inline auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();