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
        dfs(r->right,now*2+1);
        dp[now/2][0]+=dp[now][1];
        dp[now/2][1]+=min(dp[now][1],dp[now][0]);
        dp[now/2][1]++;
    }
    int minCameraCover(TreeNode* root) {
        dfs(root,1);
        return min(dp[1][0],dp[1][1]);
    }
};