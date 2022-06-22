// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    public TreeNode sortedArrayToBST(int[] nums) {
        int m = nums.length;
        if(nums.length==0){
            return null;
        }
        TreeNode t = new TreeNode(nums[m/2]);
        if(nums.length==1){
            return t;
        }
        int[] left=Arrays.copyOfRange(nums,0,m/2);
        int[] right=Arrays.copyOfRange(nums,m/2+1,m);
        t.left=sortedArrayToBST(left);
        t.right=sortedArrayToBST(right);
        return t;
    }
}