// https://leetcode.com/problems/count-complete-tree-nodes

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
    int heightl(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+heightl(root->left);
    }
    int heightr(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+heightr(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int x=heightl(root);
        int y=heightr(root);
        if(x==y) return (1<<x)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};