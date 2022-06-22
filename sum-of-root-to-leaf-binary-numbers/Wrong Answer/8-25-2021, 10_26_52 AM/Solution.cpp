// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    void dfs(TreeNode* root,int sum){
        if(root==nullptr){
            ans+=sum;
            return;
        }
        dfs(root->left,sum*2+root->val);
        dfs(root->right,sum*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans=0;
        dfs(root,0);
        return ans/2;
    }
};