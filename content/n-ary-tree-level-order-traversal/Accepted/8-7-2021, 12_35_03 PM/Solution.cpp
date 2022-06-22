// https://leetcode.com/problems/n-ary-tree-level-order-traversal

struct node{
    Node* n;
    int v;
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<node> q;
        q.push(node{root,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.v>=ans.size()){
                ans.emplace_back(vector<int>());
            }
            ans[t.v].emplace_back(t.n->val);
            for(int i=0;i<t.n->children.size();i++){
                q.push(node{t.n->children[i],t.v+1});
            }
        }
        return ans;
    }
};