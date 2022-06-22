// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        int x=countl(root);
        int y=countr(root);
        if(x==y){
            return (1<<x)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int countl(TreeNode* root){
        int h=0;
        while(root){
            root=root->left;
            h++;
        }
        return h;
    }
    int countr(TreeNode* root){
        int h=0;
        while(root){
            root=root->right;
            h++;
        }
        return h;
    }
};