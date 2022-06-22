// https://leetcode.com/problems/cheapest-flights-within-k-stops

struct edge{
    int to,d;  
};
struct path{
    int d,p=0;  
};
bool operator<(edge a,edge b){
    return a.d>b.d;
}
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<edge>> g(n);
        vector<bool> vis(n,false);
        vector<path> dis(n,path{10000,0});
        priority_queue<edge> pq;
        int m=f.size();
        for(int i=0;i<m;i++){
            g[f[i][0]].emplace_back(edge{f[i][1],f[i][2]});
        }
        pq.push(edge{src,0});
        dis[src].d=0;
        while(!pq.empty()){
            auto tmp=pq.top().to;
            pq.pop();
            if(vis[tmp]) continue;
            vis[tmp]=true;
            for(auto i : g[tmp]){
                if(dis[i.to].d>dis[tmp].d+i.d && dis[i.to].p<=k){
                    dis[i.to].d=dis[tmp].d+i.d;
                    dis[i.to].p++;
                    pq.push(edge{i.to,dis[i.to].d});
                }
            }
        }
        return dis[dst].d;
    }
};