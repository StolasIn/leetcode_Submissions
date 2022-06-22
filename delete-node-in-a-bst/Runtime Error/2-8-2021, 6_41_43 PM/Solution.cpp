// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* acc(TreeNode* root,TreeNode* root1){
        auto y=root;
        while(y->left!=nullptr){
            y=y->left;
        }
        y->left=root1;
        return y;
    }
    TreeNode* de(TreeNode* root, int key){
        if(root->left==nullptr){
            auto tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right==nullptr){
            auto tmp = root->left;
            delete root;
            return tmp;
        }
        else{
            auto tmp = root->right;
            auto tmp1 = root->left;
            delete root;
            return acc(tmp,tmp1);
        }
    }
    TreeNode* del(TreeNode* root, int key){
        if(root==nullptr) return root;
        if(key>root->val){
            root->right=del(root->right,key);
        }
        else if(key<root->val){
            root->left=del(root->left,key);
        }
        else{
            return de(root,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        del(root,key);
        return root;
    }
};