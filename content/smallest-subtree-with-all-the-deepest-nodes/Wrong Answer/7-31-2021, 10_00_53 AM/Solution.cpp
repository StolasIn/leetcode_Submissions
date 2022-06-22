// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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
    int hei;
    TreeNode* ans;
    int dfs1(TreeNode* root){
        if(root==nullptr) return 0;
        int x=dfs1(root->left);
        int y=dfs1(root->right);
        return max(x,y)+1;
    }
    int dfs2(TreeNode* root,int dis){
        if(root==nullptr) return 0;
        int x=dfs2(root->left,dis+1);
        int y=dfs2(root->right,dis+1);
        if(dis==hei){
            ans=root;
        }
        if(x==y && x==hei){
            ans=root;
        }
        return dis;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        hei=dfs1(root);
        dfs2(root,1);
        return ans;
    }
};