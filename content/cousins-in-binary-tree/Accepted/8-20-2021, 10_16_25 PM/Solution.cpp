// https://leetcode.com/problems/cousins-in-binary-tree

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
    bool f;
    int dep(TreeNode* root,int tar,int& par){
        if(root==nullptr) return 1e9;
        if(root->val==tar){
            f=true;
            return 0;
        }
        int l=dep(root->left,tar,par);
        if(f){
            par=root->val;
            f=false;
        }
        int r=dep(root->right,tar,par);
        if(f){
            par=root->val;
            f=false;
        }
        return min(l,r)+1;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        f=false;
        int p1,p2;
        return (dep(root,x,p1)==dep(root,y,p2)) && p1!=p2;
    }
};