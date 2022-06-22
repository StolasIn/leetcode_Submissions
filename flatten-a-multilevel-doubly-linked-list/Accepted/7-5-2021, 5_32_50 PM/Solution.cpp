// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<int> v;
    void dfs(Node* now){
        if(now==nullptr) return;
        v.emplace_back(now->val);
        if(now->child!=nullptr){
            dfs(now->child);
        }
        dfs(now->next);
        return;
    }
    Node* flatten(Node* head) {
        if(head==nullptr) return nullptr;
        dfs(head);
        Node* h=new Node();
        auto r=h;
        h->prev=nullptr;
        Node* tmp=nullptr;
        for(int i=0;i<v.size();i++){
            h->val=v[i];
            h->child=nullptr;
            h->prev=tmp;
            if(i!=v.size()-1){
                h->next=new Node();
                tmp=h;
                h=h->next;
            }
        }
        return r;
    }
};