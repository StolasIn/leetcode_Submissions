// https://leetcode.com/problems/range-sum-of-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int l,h;
    int sum;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        if(root->val>h) return;
        inorder(root->left);
        if(root->val>=l && root->val<=h) sum+=root->val;
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        l=low,h=high;
        sum=0;
        inorder(root);
        return sum;
    }
};