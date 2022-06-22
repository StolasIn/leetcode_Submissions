// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool ans=true;
    int point;
    void dfs(vector<vector<int>>& g,vector<int>& vis,int now,vector<bool>& haspath){
        if(ans==false) return;
        if(vis[now]==1) ans=false;
        haspath[now]=true;
        vis[now]=1;
        for(int i : g[now]){
            if(vis[now]==0)
                dfs(g,vis,i,haspath);
        }
        vis[now]=2;
    }
    bool canFinish(int c, vector<vector<int>>& num) {
        vector<vector<int>> g(c);
        vector<int> vis(c,false);
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