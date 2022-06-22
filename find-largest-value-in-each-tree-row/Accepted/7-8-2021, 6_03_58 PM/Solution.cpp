// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
        deque<pair<TreeNode*,int>> de;
        vector<vector<int>> ans;
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
        for(int i=0;i<now.size();i++){
            ans[now[i].second].emplace_back(now[i].first);
        }
        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        ans=levelOrder(root);
        for(int i=0;i<ans.size();i++){
            int ma=ans[i][0];
            for(int j=0;j<ans[i].size();j++){
                ma=max(ma,ans[i][j]);
            }
            res.emplace_back(ma);
        }
        return res;
    }
};