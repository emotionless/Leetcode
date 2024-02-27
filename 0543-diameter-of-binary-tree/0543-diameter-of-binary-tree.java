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
    int mxLen = 0;
    public int maxDiameter(TreeNode root) {
        if (root == null) return 0;
        int left = maxDiameter(root.left);
        int right = maxDiameter(root.right);
        mxLen = Math.max(mxLen, 1 + left + right);
        return 1 + Math.max(left, right);
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDiameter(root);
        return mxLen - 1;
    }
}