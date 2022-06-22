// https://leetcode.com/problems/balanced-binary-tree

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
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int x=height(root->left);
        int y=height(root->right);
        root->val=max(x,y);
        return (x>y ? x : y)+1;
    }
    bool check(TreeNode* root){
        if(root->left==nullptr || root->right==nullptr) return true;
        if(abs(root->left->val-root->right->val)>=2) return false;
        else{
            return check(root->left) && check(root->right);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        height(root);
        return check(root);
    }
};