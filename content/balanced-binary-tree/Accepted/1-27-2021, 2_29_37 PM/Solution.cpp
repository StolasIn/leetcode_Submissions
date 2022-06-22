// https://leetcode.com/problems/balanced-binary-tree

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
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int x=height(root->left);
        int y=height(root->right);
        root->val=max(x,y);
        return (x>y ? x : y)+1;
    }
    bool check(TreeNode* root){
        if(root==nullptr) return true;
        int x,y;
        if(root->left==nullptr) x=-1;
        else {x=root->left->val;}
        if(root->right==nullptr) y=-1;
        else {y=root->right->val;}
        if(abs(x-y)>=2) return false;
        else{
            return check(root->left) && check(root->right);
        }
    }
    void levelOrder(TreeNode* root) {
        deque<pair<TreeNode*,int>> de;
        vector<vector<int>> ans;
        vector<pair<int,int>> now;
        de.push_back(pair<TreeNode*,int>(root,0));
        while(de.empty()==false){
            auto tmp=de.front();
            cout<<tmp.first->val<<" ";
            de.pop_front();
            if(tmp.first->left!=nullptr){
                de.push_back(pair<TreeNode*,int>(tmp.first->left,tmp.second+1));
            }
            if(tmp.first->right!=nullptr){
                de.push_back(pair<TreeNode*,int>(tmp.first->right,tmp.second+1));
            }
        }
        cout<<endl;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        height(root);
        levelOrder(root);
        return check(root);
    }
};