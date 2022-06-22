// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool ans=true;
    int point;
    void dfs(vector<vector<int>>& g,vector<bool>& vis,int now){
        if(ans==false) return;
        if(vis[now]==true) ans=false;
        vis[now]=true;
        for(int i : g[now]){
            dfs(g,vis,i);
        }
        vis[now]=false;
    }
    bool canFinish(int c, vector<vector<int>>& num) {
        vector<vector<int>> g(c);
        vector<bool> vis(c,false);
        int n=num.size();
        point=c;
        for(int i=0;i<n;i++){
            g[num[i][1]].emplace_back(num[i][0]);
        }
        for(int i=0;i<c;i++){
            dfs(g,vis,i);
            if(ans==false) return false;
        }
        return ans;
    }
};