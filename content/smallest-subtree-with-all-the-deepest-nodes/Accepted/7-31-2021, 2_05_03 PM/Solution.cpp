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
    unordered_map<int,int> map;
    int dfs1(TreeNode* root){
        if(root==nullptr) return 0;
        int x=dfs1(root->left);
        int y=dfs1(root->right);
        if(x==y){
            map[root->val]=0;
        }
        else if(x>y){
            map[root->val]=1;   
        }
        else{
            map[root->val]=-1;
        }
        return max(x,y)+1;
    }
    TreeNode* dfs2(TreeNode* root){
        if(map[root->val]==0){
            return root;
        }
        else if(map[root->val]==1){
            return dfs2(root->left);
        }
        else{
            return dfs2(root->right);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs1(root);
        return dfs2(root);
    }
};