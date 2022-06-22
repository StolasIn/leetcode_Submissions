// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<pair<TreeNode*,int>> de;
        vector<vector<int>> ans;
        vector<vector<int>> ans1;
        if(root==nullptr) return ans;
        vector<pair<int,int>> now;
        de.push_back(pair<TreeNode*,int>(root,0));
        while(de.empty()==false){
            auto tmp=de.front();
            now.emplace_back(pair<int,int>(tmp.first->val,tmp.second));
            de.pop_front();
            if(tmp.first->left!=nullptr){
                de.push_back(pair<TreeNode*,int>(tmp.first->left,tmp.second+1));
            }
            if(tmp.first->right!=nullptr){
                de.push_back(pair<TreeNode*,int>(tmp.first->right,tmp.second+1));
            }
        }
        ans.resize(now[now.size()-1].second+1);
        ans1.resize(now[now.size()-1].second+1);
        for(int i=0;i<now.size();i++){
            ans[now[i].second].emplace_back(now[i].first);
        }
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                ans1[i].assign(ans[i].begin(),ans[i].end());
            }
            else{
                for(int j=ans[i].size()-1;j>=0;j--){
                    ans1[i].emplace_back(ans[i][j]);
                }
            }
        }
        return ans1;
    }
};