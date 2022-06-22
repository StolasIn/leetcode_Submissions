// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    void dfs(TreeNode* root,bool dir,int dis){
        if(root==nullptr) return;
        ans=max(ans,dis);
        if(dir){
            dfs(root->left,!dir,dis+1);
        }
        else{
            dfs(root->right,!dir,dis+1);
        }
        dfs(root->left,false,0);
        dfs(root->right,true,0);
    }
    int longestZigZag(TreeNode* root) {
        ans=-1;
        dfs(root->left,false,0);
        dfs(root->right,true,0);
        return ans+1;
    }
};