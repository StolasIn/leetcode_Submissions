// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    vector<int> l,r;
    void inorder(vector<int>& v,TreeNode* r){
        if(r==nullptr){
            return;
        }
        inorder(v,r->left);
        v.emplace_back(r->val);
        inorder(v,r->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l,r,ans;
        int i=0,j=0;
        inorder(l,root1);
        inorder(r,root2);
        while(i<l.size() || j<r.size()){
            if(i==l.size()){
                ans.emplace_back(r[j]);
                j++;
                continue;
            }
            else if(j==r.size()){
                ans.emplace_back(l[i]);
                i++;
                continue;
            }
            if(l[i]<r[j]){
                ans.emplace_back(l[i]);
                i++;
            }
            else{
                ans.emplace_back(r[j]);
                j++;
            }
        }
        return ans;
    }
};