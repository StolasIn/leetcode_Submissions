// https://leetcode.com/problems/path-with-maximum-probability

struct node{
    int to;
    double wid;
};
bool operator<(node a,node b){
    return a.wid<b.wid;
}
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<node> g[n];
        vector<double> dis(n,0);
        vector<bool> vis(n,false);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].emplace_back(node{edges[i][1],succ[i]});
            g[edges[i][1]].emplace_back(node{edges[i][0],succ[i]});
        }
        priority_queue<node> pq;
        pq.push(node{start,1});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            if(vis[t.to]==true) continue;
            vis[t.to]=true;
            for(int i=0;i<g[t.to].size();i++){
                if(t.wid*g[t.to][i].wid>dis[g[t.to][i].to]){
                    dis[g[t.to][i].to]=t.wid*g[t.to][i].wid;
                    pq.push(node{g[t.to][i].to,dis[g[t.to][i].to]});
                    //cout<<g[t.to][i].to<<" "<<dis[g[t.to][i].to]<<endl;
                }
            }
        }
        /*for(auto i:dis){
            cout<<i<<" ";
        }*/
        cout<<endl;
        return dis[end];
    }
};