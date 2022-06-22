// https://leetcode.com/problems/univalued-binary-tree

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
    int cmp;
    bool dfs(TreeNode* root){
        if(root==nullptr) return true;
        return root->val==cmp && dfs(root->left) && dfs(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        cmp=root->val;
        return dfs(root);
    }
};