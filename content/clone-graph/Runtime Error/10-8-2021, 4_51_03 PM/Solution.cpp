// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> map;
    Node* cloneGraph(Node* node) {
        if(map.find(node->val)!=map.end()){
            return map[node->val];
        }
        Node* tmp = new Node(node->val);
        map[node->val]=tmp;
        for(int i=0;i<node->neighbors.size();i++){
            tmp->neighbors.emplace_back(cloneGraph(node->neighbors[i]));
        }
        return tmp;
    }
};