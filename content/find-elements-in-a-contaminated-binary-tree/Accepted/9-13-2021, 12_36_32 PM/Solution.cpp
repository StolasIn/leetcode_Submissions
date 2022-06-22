// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

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
class FindElements {
public:
    TreeNode* t;
    FindElements(TreeNode* root) {
        t=root;
        re(root,0);
    }
    void re(TreeNode* r,int val){
        if(r==nullptr){
            return;
        }
        r->val=val;
        re(r->left,2*val+1);
        re(r->right,2*val+2);
    }
    bool find(int target) {
        auto r = t;
        return find_r(r,target);
    }
    bool find_r(TreeNode* r,int target){
        if(r==nullptr || r->val>target){
            return false;
        }
        if(r->val==target){
            return true;
        }
        return find_r(r->left,target) || find_r(r->right,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */