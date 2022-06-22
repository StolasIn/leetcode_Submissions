// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
        if(x==0) return y+1;
        if(y==0) return x+1;
        else return (x<y ? x : y)+1;
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return height(root);
    }
};