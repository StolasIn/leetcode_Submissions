// https://leetcode.com/problems/invert-binary-tree

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
    public void inv(TreeNode t){
        if(t==null) return;
        TreeNode tmp = t.left;
        t.left=t.right;
        t.right=tmp;
        inv(t.left);
        inv(t.right);
    }
    public TreeNode invertTree(TreeNode root) {
        inv(root);
        return root;
    }
}