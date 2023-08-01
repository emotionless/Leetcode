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
    
    private void traverse(TreeNode node, int level, Map<Integer, List<Integer>> hashMap) {
        if (node == null) return;
        if (hashMap.get(level) == null) {
            hashMap.put(level, new ArrayList<Integer>());
        }
        hashMap.get(level).add(node.val);
        traverse(node.left, level + 1, hashMap);
        traverse(node.right, level + 1, hashMap);
    }
    
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Map<Integer, List<Integer>> hashMap = new HashMap<>();
        traverse(root, 0, hashMap);
        List<Integer> keys = new ArrayList<Integer>(hashMap.keySet());
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = keys.size() - 1; i >= 0; i--) {
            ans.add(hashMap.get(keys.get(i)));
        }
        return ans;
    }
}