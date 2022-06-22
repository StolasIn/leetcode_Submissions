// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
struct node{
    Node* n;
    int v;
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr) return nullptr;
        vector<vector<int>> ans;
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