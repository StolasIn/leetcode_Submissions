// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> de;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> now;
        int cnt1=0;
        int cnt2=-1;
        int pro=1;
        de.push_back(root);
        while(de.empty()==false){
            auto tmp=de.front();
            now.emplace_back(tmp->val);
            de.pop_front();
            cnt1++;
            if(cnt1>=pro){
                ans.emplace_back(now);
                now.clear();
                pro*=2;
                cnt1=0;
            }
            if(tmp->left!=nullptr){
                de.push_back(tmp->left);
            }
            else{
                cnt1++;
            }
            if(tmp->right!=nullptr){
                de.push_back(tmp->right);
            }
            else{
                cnt1++;
            }
        }
        return ans;
    }
};