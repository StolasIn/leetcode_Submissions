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
public:
    bool is_symmetic(TreeNode* root){
        if((!root->left && root->right) || (root->left && !root->right)) return false;
        else if(!root->left && !root->right){
            return true;
        }
        else{
            return is_symmetic(root->left)+is_symmetic(root->right);
        }
    }
    bool isSymmetric(TreeNode* root) {
        return is_symmetic(root);
    }
};