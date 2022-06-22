// https://leetcode.com/problems/path-sum

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
    bool has=false;
    void dfs(TreeNode* root, int t,int s){
        if(root==nullptr || has) return;
        if(s==t) has=true;
        dfs(root->left,t,s+root->val);
        dfs(root->right,t,s+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        dfs(root,targetSum,root->val);
        return has;
    }
};