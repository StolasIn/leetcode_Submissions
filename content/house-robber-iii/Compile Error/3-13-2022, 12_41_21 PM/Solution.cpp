// https://leetcode.com/problems/house-robber-iii

class Solution {
public:
    unordered_map<TreeNode*, int> m;
    int memoisedRob(TreeNode* r) {
        if(m.find(r)!=m.end()){
            return m[r];
        }
        return m[r] = rob(r);
    }
    int rob(TreeNode* r) {
        int take = r->val;
        if(root==nullptr){
            return 0;
        }
        if(r->left!=nullptr){
            now+=memoisedRob(root->left->left)+memoisedRob(root->left->right);
        }
        if(r-right!=nullptr){
            now+=memoisedRob(root->right->left)+memoisedRob(root->right->right);
        }
        return max(take,memoisedRob(root->left) + memoisedRob(root->right));
    }
};