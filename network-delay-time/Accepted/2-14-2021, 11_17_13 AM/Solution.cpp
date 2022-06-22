// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<int> ans(n+1,INT_MAX);
        int ma=-1;
        vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> dag(n+1);
        for(int i=0;i<m;i++){
            dag[times[i][0]].emplace_back(pair<int,int>(times[i][2],times[i][1]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0,k));
        ans[k]=0;
        while(!pq.empty()){
            auto tmp=pq.top();
            pq.pop();
            // if(vis[tmp.second]==true) continue;
            // vis[tmp.second]=true;
            for(auto i : dag[tmp.second]){
                if(ans[i.second]>ans[tmp.second]+i.first){
                    ans[i.second]=ans[tmp.second]+i.first;
                }
                if(vis[i.second]==false){
                    pq.push(pair<int,int>(i.first,i.second));
                    vis[tmp.second]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            ma=max(ma,ans[i]);
        }
        if(ma==INT_MAX) return -1;
        return ma;
    }
};