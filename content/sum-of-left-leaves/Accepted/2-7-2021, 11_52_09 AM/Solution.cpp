// https://leetcode.com/problems/sum-of-left-leaves

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
    //dir = false : left
    //dir = true : right
    int ans=0;
    void re(TreeNode* root,bool dir){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr && dir==false){
            ans+=root->val;
            return;
        }
        re(root->left,false);
        re(root->right,true);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        re(root->left,false);
        re(root->right,true);
        return ans;
    }
};