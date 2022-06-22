// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int dep(TreeNode root){
        if(root==null) return 0;
        int l=dep(root.left);
        int r=dep(root.right);
        return Math.max(l,r)+1;
    }
    public int maxDepth(TreeNode root) {
        return dep(root);
    }
}