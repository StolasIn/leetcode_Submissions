// https://leetcode.com/problems/delete-nodes-and-return-forest

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
    unordered_set<int> s;
    vector<TreeNode*> ans;
    TreeNode* re(TreeNode* r){
        if(r==nullptr){
            return nullptr;
        }
        if(s.find(r->val)!=s.end()){
            r->left=re(r->left);
            r->right=re(r->right);
            if(r->left!=nullptr) ans.emplace_back(r->left);
            if(r->right!=nullptr) ans.emplace_back(r->right);
            return nullptr;
        }
        else{
            r->left=re(r->left);
            r->right=re(r->right);
            return r;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        for(int i=0;i<del.size();i++){
            s.insert(del[i]);
        }
        if(s.find(root->val)==s.end()){
            ans.emplace_back(root);
        }
        re(root);
        return ans;
    }
};