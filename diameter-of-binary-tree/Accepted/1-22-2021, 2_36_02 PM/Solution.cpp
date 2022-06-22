// https://leetcode.com/problems/diameter-of-binary-tree

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
    int ans;
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int x=height(root->left);
        int y=height(root->right);
        ans=max(ans,x+y);
        return (x>y ? x : y)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        height(root);
        return ans;
    }
};