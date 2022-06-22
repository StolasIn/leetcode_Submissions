// https://leetcode.com/problems/longest-univalue-path

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
    void dfs(TreeNode* root,int from,int dis){
        ans=max(ans,dis);
        if(root==nullptr) return;
        if(from==root->val){
            dfs(root->left,root->val,dis+1);
            dfs(root->right,root->val,dis+1);
        }
        else{
            dfs(root->left,root->val,0);
            dfs(root->right,root->val,0);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        dfs(root,root->val,0);
        return ans;
    }
};