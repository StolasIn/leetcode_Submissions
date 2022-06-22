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
    struct no{
        Node* v;
        int level;  
    };
class Solution {
public:
    //bfs
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<no> qu;
        int cnt=0;
        qu.push(no{root,0});
        while(!qu.empty()){
            auto tmp=qu.front();
            qu.pop();
            for(auto i : tmp.v->children){
                qu.push(no{i,tmp.level+1});
            }
            if(tmp.level>=res.size()){
                res.emplace_back(vector<int>());
            }
            res[tmp.level].emplace_back(tmp.v->val);
        }
        return res;
    }
};