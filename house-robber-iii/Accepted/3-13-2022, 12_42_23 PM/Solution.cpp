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
        if(r==nullptr){
            return 0;
        }
        int take = r->val;
        if(r->left!=nullptr){
            take+=memoisedRob(r->left->left)+memoisedRob(r->left->right);
        }
        if(r->right!=nullptr){
            take+=memoisedRob(r->right->left)+memoisedRob(r->right->right);
        }
        return max(take,memoisedRob(r->left) + memoisedRob(r->right));
    }
};