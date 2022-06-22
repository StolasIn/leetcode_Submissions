// https://leetcode.com/problems/same-tree

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
    bool is_same(TreeNode* p,TreeNode* q){
        return ((p && q) && p->val==q->val && is_same(p->left,q->left) && is_same(p->right,q->right) ||(!p && !q));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return is_same(p,q);
    }
};