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
    int level = 0, value = -1;
    void traverse(TreeNode cur, int lvl) {
        if (cur == null) return;
        if (lvl > level) {
            value = cur.val;
            level = lvl;
        }
        traverse(cur.left, lvl + 1);
        traverse(cur.right, lvl + 1);
    }
    
    public int findBottomLeftValue(TreeNode root) {
        traverse(root, 1);
        return value;
    }
}