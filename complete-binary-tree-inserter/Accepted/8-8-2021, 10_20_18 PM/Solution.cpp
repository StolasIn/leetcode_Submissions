// https://leetcode.com/problems/complete-binary-tree-inserter

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
class CBTInserter {
public:
    vector<TreeNode*> v;
    CBTInserter(TreeNode* root) {
        v.emplace_back(nullptr);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t==nullptr) continue;
            v.emplace_back(t);
            q.push(t->left);
            q.push(t->right);
        }
    }
    int insert(int val) {
        TreeNode* tmp = new TreeNode(val);
        v.emplace_back(tmp);
        int t=v.size()-1;
        if(t%2==0){
            v[t/2]->left=tmp;
        }
        else{
            v[t/2]->right=tmp;
        }
        return v[t/2]->val;
    }
    
    TreeNode* get_root() {
        return v[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */