// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    vector<long long> v;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        v.emplace_back(root->val);
        inorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        inorder(root);
        int mi=*min_element(v.begin(),v.end());
        long long mi2=2147483648;
        for(int i=0;i<v.size();i++){
            if(v[i]>mi && mi2>v[i]){
                mi2=min(mi2,v[i]);
            }
        }
        if(mi2==2147483648) return -1;
        return mi2;
    }
};