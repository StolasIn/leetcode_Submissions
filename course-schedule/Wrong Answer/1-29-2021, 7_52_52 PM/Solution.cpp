// https://leetcode.com/problems/course-schedule

class Solution {
public:
    int point;
    bool dfs(vector<vector<int>>& g,vector<bool>& vis,int now,vector<bool>& haspath){
        if(vis[now]==true) return false;
        vis[now]=haspath[now]=true;
        for(int i : g[now]){
            if(vis[i]==true){
                if(dfs(g,vis,i,haspath)==false){
                    return false;
                }
            }
        }
        vis[now]=false;
        return true;
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
                if(dfs(g,vis,i,haspath)==false) return false;
        }
        return true;
    }
};