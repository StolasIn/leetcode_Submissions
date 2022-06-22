// https://leetcode.com/problems/construct-string-from-binary-tree

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
    string ans;
    string re(TreeNode* root){
        if(root==nullptr) return "";
        string str;
        if(root->left==nullptr && root->right==nullptr){
            return to_string(root->val);
        }
        else if(root->left==nullptr && root->right!=nullptr){
            return to_string(root->val)+"()"+'('+re(root->right)+')';
        }
        else if(root->left!=nullptr && root->right==nullptr){
            return to_string(root->val)+'('+re(root->left)+')';
        }
        else{
            str=to_string(root->val)+'('+re(root->left)+')'+'('+re(root->right)+')';
            return str;
        }
    }
    string tree2str(TreeNode* root) {
        return re(root);
    }
};