// https://leetcode.com/problems/add-one-row-to-tree

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
    int v,dph;
    void dfs(TreeNode* root,int dis){
        if(dis==dph-2){
            auto tmp1=root->left;
            root->left=new TreeNode(v);
            root->left->left=tmp1;
            tmp1=root->right;
            root->right=new TreeNode(v);
            root->right->right=tmp1;
            return;
        }
        dfs(root->left,dis+1);
        dfs(root->right,dis+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* head=new TreeNode(val);
            head->left=root;
            return head;
        }
        v=val;
        dph=depth;
        dfs(root,0);
        return root;
    }
};