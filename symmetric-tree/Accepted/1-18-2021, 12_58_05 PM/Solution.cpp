// https://leetcode.com/problems/symmetric-tree

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
    bool is_symmetic(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right || left->val!=right->val) return false;
        return is_symmetic(left->left,right->right) && is_symmetic(left->right,right->left);
    }
public:
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return is_symmetic(root->left,root->right);
    }
};