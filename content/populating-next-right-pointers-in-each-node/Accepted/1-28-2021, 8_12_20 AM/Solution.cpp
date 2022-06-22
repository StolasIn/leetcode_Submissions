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
    Node* connect(Node* root) {
        int j;
        if(root==nullptr) return root;
        deque<pair<Node*,int>> de;
        vector<vector<Node*>> ans;
        vector<pair<Node*,int>> now;
        de.push_back(pair<Node*,int>(root,0));
        while(de.empty()==false){
            auto tmp=de.front();
            now.emplace_back(pair<Node*,int>(tmp.first,tmp.second));
            de.pop_front();
            if(tmp.first->left!=nullptr){
                de.push_back(pair<Node*,int>(tmp.first->left,tmp.second+1));
            }
            if(tmp.first->right!=nullptr){
                de.push_back(pair<Node*,int>(tmp.first->right,tmp.second+1));
            }
        }
        ans.resize(now[now.size()-1].second+1);
        for(int i=0;i<now.size();i++){
            ans[now[i].second].emplace_back(now[i].first);
        }
        for(int i=0;i<ans.size();i++){
            for(j=0;j<ans[i].size()-1;j++){
                ans[i][j]->next=ans[i][j+1];
            }
            ans[i][j]->next=nullptr;
        }
        return root;
    }
};