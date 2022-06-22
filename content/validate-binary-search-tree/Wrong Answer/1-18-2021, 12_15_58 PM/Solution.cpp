// https://leetcode.com/problems/validate-binary-search-tree

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
    bool is_valid(TreeNode* root){
        if(root->left && root->val>root->left->val && root->right && root->val<root->right->val){
            return is_valid(root->left) && is_valid(root->right);
        }
        else if(root->left && root->val>root->left->val && !root->right){
            return is_valid(root->left);
        }
        else if(!root->left && root->right && root->val<root->right->val){
            return is_valid(root->right);
        }
        else if(!root->left && !root->right){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root);
    }
};