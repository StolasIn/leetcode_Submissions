// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    vector<TreeNode*> re(int l,int r){
        if(r<l){
            return {nullptr};
        }
        else if(r==l){
            return {new TreeNode(l)};
        }
        else{
            vector<TreeNode*> ans;
            for(int i=l;i<=r;i++){
                vector<TreeNode*> left = re(l,i-1),right = re(i+1,r);
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        ans.emplace_back(new TreeNode(i,left[j],right[k]));
                    }
                }
            }
            return ans;
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        return re(1,n);
    }
};