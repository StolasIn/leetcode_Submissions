// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> ans;
    void tr(TreeNode* root,string& now){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            string str=now;
            now+=to_string(root->val);
            ans.emplace_back(now);
            now=str;
        }
        string str=now;
        now+=to_string(root->val);
        now+="->";
        tr(root->left,now);
        tr(root->right,now);
        now=str;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        tr(root,str);
        return ans;
    }
};