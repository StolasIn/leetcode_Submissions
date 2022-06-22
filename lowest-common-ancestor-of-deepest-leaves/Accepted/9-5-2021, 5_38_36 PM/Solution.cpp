// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves

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
    int h;
    TreeNode* ans;
    int dep(TreeNode* r){
        if(r==nullptr) return 0;
        int x = dep(r->left);
        int y = dep(r->right);
        return max(x,y)+1;
    }
    int re(TreeNode* r,int dis){
        if(r==nullptr) return dis;
        int x = re(r->left,dis+1);
        int y = re(r->right,dis+1);
        if(x==h && y==h){
            ans=r;
        }
        return max(x,y);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        h=dep(root);
        re(root,0);
        return ans;
    }
};