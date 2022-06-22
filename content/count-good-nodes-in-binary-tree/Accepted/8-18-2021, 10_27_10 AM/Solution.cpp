// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int ans=0;
    void dfs(TreeNode* root,int ma){
        if(root==nullptr) return;
        if(root->val>=ma){
            ans++;
            ma=root->val;
        }
        dfs(root->left,ma);
        dfs(root->right,ma);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,-1e9);
        return ans;
    }
};