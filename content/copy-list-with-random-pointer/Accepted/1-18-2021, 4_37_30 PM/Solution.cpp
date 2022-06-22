// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;   // map from current node to deep node
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        if(map.find(head) != map.end()) return map[head];
        Node* n = new Node(head->val);
        map[head] = n;
        n->next = copyRandomList(head->next);
        n->random = copyRandomList(head->random);
        
        return n;
    }
};