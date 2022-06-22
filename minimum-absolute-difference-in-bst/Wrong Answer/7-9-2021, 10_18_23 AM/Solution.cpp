// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int ans=1000000;
    void inorder(TreeNode* root,int pre){
        if(root==nullptr){
            return;
        }
        inorder(root->left,root->val);
        ans=min(ans,abs(root->val-pre));
        inorder(root->right,root->val);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root,-100000);
        return ans;
    }
};