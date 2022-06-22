// https://leetcode.com/problems/trim-a-binary-search-tree

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
    int lo,hi;
    TreeNode* re(TreeNode* root){
        if(root==nullptr) return root;
        if(root->val>hi){
            return root->left=re(root->left);
        }
        else if(root->val<lo){
            return root->right=re(root->right);
        }
        else{
            root->left=re(root->left);
            root->right=re(root->right);
            return root;
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        lo=low;
        hi=high;
        return re(root);
    }
};