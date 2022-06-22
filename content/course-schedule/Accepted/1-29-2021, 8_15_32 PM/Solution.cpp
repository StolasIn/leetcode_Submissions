// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool ans=true;
    int point;
    void dfs(vector<vector<int>>& g,vector<bool>& vis,int now,vector<bool>& haspath){
        if(ans==false) return;
        if(vis[now]==true) ans=false;
        if(haspath[now]) return;
        vis[now]=haspath[now]=true;
        for(int i : g[now]){
            dfs(g,vis,i,haspath);
        }
        vis[now]=false;
    }
    bool canFinish(int c, vector<vector<int>>& num) {
        vector<vector<int>> g(c);
        vector<bool> vis(c,false);
        vector<bool> haspath(c,false);
        int n=num.size();
        point=c;
        for(int i=0;i<n;i++){
            g[num[i][1]].emplace_back(num[i][0]);
        }
        for(int i=0;i<c;i++){
            if(haspath[i]==false)
                dfs(g,vis,i,haspath);
            if(ans==false) return false;
        }
        return ans;
    }
};