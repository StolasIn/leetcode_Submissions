// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int findBottomLeftValue(TreeNode* root) {
        deque<pair<TreeNode*,int>> de;
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
        int ma=now[now.size()-1].second;
        for(int i=now.size()-1;i>=0;i--){
            if(ma!=now[i].second){
                ma=now[i+1].first;
                break;
            }
        }
        return ma;
    }
};