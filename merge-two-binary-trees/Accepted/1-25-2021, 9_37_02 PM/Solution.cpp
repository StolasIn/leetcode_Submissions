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
    TreeNode* merge1(TreeNode* t1, TreeNode* t2){
        if(t1==nullptr && t2==nullptr) return nullptr;
        else if(t1==nullptr) return t2;
        else if(t2==nullptr) return t1;
        else t1->val+=t2->val;
        t1->left=merge1(t1->left,t2->left);
        t1->right=merge1(t1->right,t2->right);
        return t1;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==nullptr) return t2;
        else if(t2==nullptr) return t1;
        merge1(t1,t2);
        return t1;
    }
};