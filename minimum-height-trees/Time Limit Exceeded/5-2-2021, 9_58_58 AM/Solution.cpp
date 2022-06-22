// https://leetcode.com/problems/minimum-height-trees

class Solution {
public:
    int dfs(vector<int> g[],int now,int from){
        int h=-1;
        for(int i=0;i<g[now].size();i++){
            if(g[now][i]!=from) h=max(h,dfs(g,g[now][i],now));
        }
        return h+1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        int m=e.size();
        vector<int> g[n];
        for(int i=0;i<m;i++){
            g[e[i][0]].emplace_back(e[i][1]);
            g[e[i][1]].emplace_back(e[i][0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.emplace_back(dfs(g,i,-1));
        }
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            mi=min(mi,ans[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i]==mi){
                res.emplace_back(i);
            }
        }
        return res;
    }
};