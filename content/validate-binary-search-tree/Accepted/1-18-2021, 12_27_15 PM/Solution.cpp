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
    bool is_valid(TreeNode* root,long long low,long long high){
        if(root->left && root->val>root->left->val && root->right && root->val<root->right->val && root->val>low && root->val<high){
            return is_valid(root->left,low,root->val) && is_valid(root->right,root->val,high);
        }
        else if(root->left && root->val>root->left->val && !root->right && root->val>low && root->val<high){
            return is_valid(root->left,low,root->val);
        }
        else if(!root->left && root->right && root->val<root->right->val && root->val>low && root->val<high){
            return is_valid(root->right,root->val,high);
        }
        else if(!root->left && !root->right && root->val>low && root->val<high){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root,-4000000000,4000000000);
    }
};