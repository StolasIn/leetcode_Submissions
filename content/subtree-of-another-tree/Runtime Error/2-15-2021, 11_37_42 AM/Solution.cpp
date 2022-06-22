// https://leetcode.com/problems/subtree-of-another-tree

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
    TreeNode* find(TreeNode* s, TreeNode* t){
        if(s==nullptr) return nullptr;
        if(s->val==t->val){
            return s;
        }
        auto x=find(s->left,t);
        auto y=find(s->right,t);
        if(x!=nullptr){
            return x;
        }
        else if(y!=nullptr){
            return y;
        }
        return nullptr;
    }
    bool isequ(TreeNode* s, TreeNode* t){
        return (s->val==t->val)&&(s->left==nullptr && t->left==nullptr)||isequ(s->left,t->left)&&(s->right==nullptr && t->right==nullptr)||isequ(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isequ(find(s,t),t);
    }
};