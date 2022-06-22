// https://leetcode.com/problems/merge-two-binary-trees

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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(r1==nullptr && r2==nullptr){
            return nullptr;
        }
        TreeNode* now = new TreeNode(0);
        if(r1!=nullptr && r2!=nullptr){
            now->val = r1->val + r2->val;
            now->left = mergeTrees(r1->left,r2->left);
            now->right = mergeTrees(r1->right,r2->right);
        }
        else if(r1!=nullptr){
            now = r1;
        }
        else{
            now = r2;
        }
        return now;
    }
};