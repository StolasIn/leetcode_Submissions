// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> map = vector<Node*>(20);
    void con(Node* r,int h){
        if(r==nullptr){
            return;
        }
        r->next = nullptr;
        if(map[h]!=nullptr){
            map[h]->next = r;
            map[h] = r;
        }
        else{
            map[h] = r;
        }
        con(r->left,h+1);
        con(r->right,h+1);
    }
    Node* connect(Node* root) {
        con(root,0);
        return root;
    }
};