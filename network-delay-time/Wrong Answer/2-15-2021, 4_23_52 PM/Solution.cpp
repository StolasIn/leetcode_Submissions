// https://leetcode.com/problems/network-delay-time

struct edge{
    int to,d;
};
bool operator<(edge a, edge b){
    return a.d>b.d;
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int m=t.size();
        int ma=-1;
        int tmp,i1,i2;
        vector<bool> vis(n+1,false);
        vector<int> dis(n+1,1000000);
        vector<vector<edge>> g(n+1);
        for(int i=0;i<m;i++){
            g[t[i][0]].emplace_back(edge{t[i][1],t[i][2]});
        }
        dis[k]=0;
        for(int i=1;i<=n;i++){
            for(auto j : g[i]){
                if(dis[j.to]>dis[i]+j.d){
                    dis[j.to]=dis[i]+j.d;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==1000000) return -1;
            ma=max(ma,dis[i]);
        }
        return ma;
    }
};