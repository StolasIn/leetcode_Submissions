// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool ans=true;
    int point;
    void dfs(vector<vector<bool>>& g,vector<bool>& vis,int now){
        if(ans==false) return;
        if(vis[now]==true) {ans=false; cout<<now<<endl;}
        vis[now]=true;
        for(int i=0;i<point;i++){
            if(g[now][i]==true){
                dfs(g,vis,i);
            }
        }
        vis[now]=false;
    }
    bool canFinish(int c, vector<vector<int>>& num) {
        vector<vector<bool>> g(c,vector<bool>(c,false));
        vector<bool> vis(c,false);
        int n=num.size();
        point=c;
        for(int i=0;i<n;i++){
            g[num[i][1]][num[i][0]]=true;
        }
        /*for(int i=0;i<g.size();i++){
            for(int j=0;j<g.size();j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<c;i++){
            vis=vector<bool>(c,false);
            dfs(g,vis,i);
        }
        cout<<endl;
        return ans;
    }
};