// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    vector<vector<int>> g;
    unordered_set<int> vis;
    vector<bool> root;
    bool flag;
    void dfs(int now){
        if(now==-1) return;
        if(vis.find(now)!=vis.end()){
            flag=false;
            return;
        }
        vis.insert(now);
        dfs(g[now][0]);
        dfs(g[now][1]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        g.resize(n);
        root.assign(n,false);
        int rt=0;
        for(int i=0;i<l.size();i++){
            g[i].emplace_back(l[i]);
            g[i].emplace_back(r[i]);
            if(l[i]!=-1)root[l[i]]=true;
            if(r[i]!=-1)root[r[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(root[i]==false){
                rt=i;
                break;
            }
        }
        flag=true;
        dfs(rt);
        if(flag){
            if(vis.size()<n) return false;
            return true;
        }
        else{
            return false;
        }
    }
};