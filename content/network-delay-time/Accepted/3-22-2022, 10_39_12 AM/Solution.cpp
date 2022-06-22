// https://leetcode.com/problems/network-delay-time

struct node{
    int to,d;
    bool operator<(const node& a) const {
        return d>a.d;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int m = t.size();
        vector<vector<node>> g(n+1);
        vector<int> dis(n+1,INT_MAX);
        vector<bool> vis(n+1,false);
        priority_queue<node> pq;
        for(int i=0;i<m;i++){
            g[t[i][0]].emplace_back(node{t[i][1],t[i][2]});
        }
        dis[k] = 0;
        pq.push(node{k,0});
        while(!pq.empty()){
            node no = pq.top();
            pq.pop();
            if(vis[no.to]==true){
                continue;
            }
            vis[no.to] = true;
            for(int i=0;i<g[no.to].size();i++){
                if(dis[g[no.to][i].to]>no.d+g[no.to][i].d){
                    dis[g[no.to][i].to] = no.d+g[no.to][i].d;
                    pq.push(node{g[no.to][i].to,dis[g[no.to][i].to]});
                }
            }
        }
        int ma = INT_MIN;
        for(int i=1;i<dis.size();i++){
            ma = max(ma,dis[i]);
        }
        return ma == INT_MAX? -1:ma;
    }
};