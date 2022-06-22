// https://leetcode.com/problems/cousins-in-binary-tree

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
    int dep(TreeNode* root,int tar){
        if(root==nullptr) return 1e9;
        if(root->val==tar) return 0;
        return min(dep(root->left,tar),dep(root->right,tar))+1;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return dep(root,x)==dep(root,y);
    }
};