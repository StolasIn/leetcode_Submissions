// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<int> ans(n+1,INT_MAX);
        int ma=-1,i1,i2;
        vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> dag(n+1);
        for(int i=0;i<m;i++){
            dag[times[i][0]].emplace_back(make_pair(times[i][2],times[i][1]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,k));
        ans[k]=0;
        while(!pq.empty()){
            auto tmp=pq.top().second;
            pq.pop();
            if(vis[tmp]==true) continue; 
            vis[tmp]=true;
            for(auto& i : dag[tmp]){
                i1=i.first;
                i2=i.second;
                if(ans[i2]>ans[tmp]+i1){
                    ans[i2]=ans[tmp]+i1;
                    pq.push(make_pair(i1,i2));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==INT_MAX) return -1;
            ma=max(ma,ans[i]);
        }
        return ma;
    }
};