// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool ans=true;
    int point;
    void dfs(vector<vector<bool>>& g,vector<bool>& vis,int now){
        if(ans==false) return;
        if(vis[now]==true) ans=false;
        vis[now]=true;
        for(int i=0;i<point;i++){
            if(g[now][i]==true){
                dfs(g,vis,i);
            }
        }
    }
    bool canFinish(int c, vector<vector<int>>& num) {
        vector<vector<bool>> g(c,vector<bool>(c,false));
        int n=num.size();
        point=c;
        for(int i=0;i<n;i++){
            g[num[i][0]][num[i][1]]=true;
        }
        for(int i=0;i<c;i++){
            vector<bool> vis(c,false);
            dfs(g,vis,i);
        }
        return ans;
    }
};