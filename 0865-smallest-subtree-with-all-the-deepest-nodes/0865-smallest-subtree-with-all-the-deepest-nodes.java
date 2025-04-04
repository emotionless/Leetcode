/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode ans;
    int depth(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(depth(node.left), depth(node.right));
    }

    int solve(TreeNode node, int d) {
        if (node == null) return 0;
        else if (d == 1) {
            ans = node;
            return 1;
        }
        int l = solve(node.left, d - 1);
        int r = solve(node.right, d - 1);
        if (l == r && l == 1) {
            ans = node;
        }
        return Math.max(l, r);
    }
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        int d = depth(root);
        solve(root, d);
        return ans;
    }
}