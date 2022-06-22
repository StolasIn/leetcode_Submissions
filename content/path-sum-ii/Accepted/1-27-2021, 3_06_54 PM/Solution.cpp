// https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int t,int s,vector<int>& now){
        if(root==nullptr) return;
        if(s+root->val==t && root->left==nullptr && root->right==nullptr){
            now.emplace_back(root->val);
            ans.emplace_back(now);
            now.pop_back();
        }
        now.emplace_back(root->val);
        dfs(root->left,t,s+root->val,now);
        dfs(root->right,t,s+root->val,now);
        now.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> now;
        dfs(root,targetSum,0,now);
        return ans;
    }
};