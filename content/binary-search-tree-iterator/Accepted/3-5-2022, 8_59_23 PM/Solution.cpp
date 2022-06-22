// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    TreeNode* r;
    map<TreeNode*,TreeNode*> par;
    void built(TreeNode* r){
        if(r==nullptr){
            return;
        }
        if(r->left!=nullptr){
            par[r->left] = r;
        }
        if(r->right!=nullptr){
            par[r->right] = r;
        }
        built(r->left);
        built(r->right);
    }
    BSTIterator(TreeNode* root) {
        r = root;
        par[root] = nullptr;
        built(root);
        while(r->left!=nullptr){
            r = r->left;
        }
    }
    
    int next() {
        int ans = r->val;
        if(r->right!=nullptr){
            r = r->right;
            while(r->left!=nullptr){
                r = r->left;
            }
        }
        else{
            while(par[r]!=nullptr && par[r]->right==r){
                r = par[r];
            }
            r = par[r];
        }
        return ans;
    }
    
    bool hasNext() {
        return r!=nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */