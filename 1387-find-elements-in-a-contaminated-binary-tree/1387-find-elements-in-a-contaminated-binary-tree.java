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
class FindElements {

    void dfs(TreeNode node, int val) {
        if (node == null) return;
        hashMap.put(val, true);
        dfs(node.left, val * 2 + 1);
        dfs(node.right, val * 2 + 2);
    }

    public FindElements(TreeNode root) {
        dfs(root, 0);
    }
    
    public boolean find(int target) {
        return hashMap.getOrDefault(target, false);
    }
    private HashMap<Integer, Boolean> hashMap = new HashMap<>();
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */