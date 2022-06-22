// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

struct node{
    int to,d;
};
class Solution {
public:
    int c;
    vector<bool> vis;
    vector<node> g[101];
    void dfs(int now,int d){
        if(d<0 || vis[now]==true) return;
        c++;
        vis[now]=true;
        for(int i=0;i<g[now].size();i++){
            dfs(g[now][i].to,d-g[now][i].d);
        }
    }
    int findTheCity(int n, vector<vector<int>>& e, int dis) {
        vis=vector<bool>(n,false);
        int ans=-1,mi=INT_MAX;
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        for(int i=0;i<e.size();i++){
            g[e[i][0]].emplace_back(node{e[i][1],e[i][2]});
            g[e[i][1]].emplace_back(node{e[i][0],e[i][2]});
        }
        for(int i=0;i<n;i++){
            c=0;
            vis=vector<bool>(n,false);
            dfs(i,dis);
            if(c<=mi){
                mi=c;
                ans=i;
            }
        }
        return ans;
    }
};