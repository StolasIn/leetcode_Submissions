// https://leetcode.com/problems/network-delay-time

struct edge{
    int to,d;
    bool operator<(edge a) const {
        return a.d<d;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<edge> g[n+1];
        vector<int> dis(n+1,1e9);
        vector<bool> vis(n+1,false);
        int ma=-1;
        priority_queue<edge> pq;
        dis[k]=0;
        for(int i=0;i<t.size();i++){
            g[t[i][0]].emplace_back(edge{t[i][1],t[i][2]});
        }
        pq.push(edge{k,0});
        while(!pq.empty()){
            auto t = pq.top().to;
            pq.pop();
            if(vis[t]==true){
                continue;
            }
            vis[t]=true;
            for(int i=0;i<g[t].size();i++){
                if(dis[g[t][i].to]>dis[t]+g[t][i].d){
                    dis[g[t][i].to]=dis[t]+g[t][i].d;
                    pq.push(edge{g[t][i].to,dis[g[t][i].to]});
                }
            }
        }
        for(int i=1;i<dis.size();i++){
            ma=max(ma,dis[i]);
        }
        if(ma==1e9) return -1;
        return ma;
    }
};