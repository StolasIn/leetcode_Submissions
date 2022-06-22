// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    bool flag;
    void dfs(int now,int from){
        if(vis[now]==true){
            flag=true;
            return;
        }
        vis[now]=true;
        for(int i=0;i<g[now].size();i++){
            if(g[now][i]==from) continue;
            dfs(g[now][i],now);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        g.resize(n+1);
        vis.assign(n+1,false);
        for(int i=0;i<dis.size();i++){
            g[dis[i][0]].emplace_back(dis[i][1]);
            g[dis[i][1]].emplace_back(dis[i][0]);
        }
        flag=false;
        for(int i=1;i<=n;i++){
            if(flag) return false;
            if(vis[i]==false){
                dfs(i,-1);
            }
        }
        return true;
    }
};