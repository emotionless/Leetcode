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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int level = 0;
        while (q.size() > 0) {
            Queue<TreeNode> copyQ = new LinkedList<>();
            if (level%2 == 0) {
                int val = 0;
                while (q.size() > 0) {
                    TreeNode peek = q.poll();
                    if (peek.val <= val || (1 != peek.val%2)) return false;
                    if (peek.left != null) {
                        copyQ.add(peek.left);
                    }
                    if (peek.right != null) {
                        copyQ.add(peek.right);
                    }
                    val = peek.val;
                }
            } else {
                int val = 1000001;
                while (q.size() > 0) {
                    TreeNode peek = q.poll();
                    if (peek.val >= val || (0 != peek.val%2)) return false;
                    if (peek.left != null) {
                        copyQ.add(peek.left);
                    }
                    if (peek.right != null) {
                        copyQ.add(peek.right);
                    }
                    val = peek.val;
                }
            }
            q = copyQ;
            level++;
        }
        return true;
    }
}