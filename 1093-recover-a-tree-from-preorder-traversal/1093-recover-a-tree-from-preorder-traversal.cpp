class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return helper(traversal, index, 0);
    }

private:
    TreeNode* helper(const string& traversal, int& index, int depth) {
        if (index >= traversal.size()) return nullptr;

        // Count the number of dashes
        int dashCount = 0;
        while (index + dashCount < traversal.size() &&
               traversal[index + dashCount] == '-') {
            dashCount++;
        }

        // If the number of dashes doesn't match the current depth, return null
        if (dashCount != depth) return nullptr;

        // Move index past the dashes
        index += dashCount;

        // Extract the node value
        int value = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }

        // Create the current node
        TreeNode* node = new TreeNode(value);

        // Recursively build the left and right subtrees
        node->left = helper(traversal, index, depth + 1);
        node->right = helper(traversal, index, depth + 1);

        return node;
    }
};