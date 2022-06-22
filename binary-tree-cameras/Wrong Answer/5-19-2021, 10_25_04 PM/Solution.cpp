// https://leetcode.com/problems/binary-tree-cameras

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
    int dp[2021][2];
    void dfs(TreeNode* r,int now){
        if(r==nullptr) return;
        dp[now][0]=dp[now][1]=0;
        dfs(r->left,now*2);
        dp[now/2][0]+=dp[now][1];
        dp[now/2][1]+=min(dp[now][1],dp[now][0]);
        dp[now/2][1]++;
        dfs(r->right,now*2+1);
    }
    int minCameraCover(TreeNode* root) {
        if(root==nullptr) return 0;
        dfs(root,1);
        return max(min(dp[0][0],dp[0][1]),1);
    }
};