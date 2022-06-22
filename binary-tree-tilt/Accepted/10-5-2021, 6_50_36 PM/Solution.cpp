// https://leetcode.com/problems/binary-tree-tilt

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
    int gen(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        root->val+=gen(root->left)+gen(root->right);
        return root->val;
    }
    int re(TreeNode* root){
        int l,r;
        if(root==nullptr) return 0;
        if(root->left==nullptr){
            l=0;
        }
        else{
            l=re(root->left);
        }
        if(root->right==nullptr){
            r=0;
        }
        else{
            r=re(root->right);
        }
        int t=root->val; 
        root->val=abs(r-l);
        ans+=root->val;
        return t;
    }
    int findTilt(TreeNode* root) {
        gen(root);
        ans=0;
        re(root);
        return ans;
    }
};