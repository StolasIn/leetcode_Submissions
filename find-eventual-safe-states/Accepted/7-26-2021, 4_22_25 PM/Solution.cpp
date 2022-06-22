// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    vector<int> vis;
    bool dfs(vector<vector<int>>& g,vector<bool>& v,int now){
        if(vis[now]!=-1) return vis[now];
        if(v[now]==true) return false;
        if(g[now].size()==0){
            return vis[now]=true;
        }
        else{
            bool flag=true;
            for(int i=0;i<g[now].size();i++){
                v[now]=true;
                flag&=dfs(g,v,g[now][i]);
                v[now]=false;
            }
            return vis[now]=flag;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vis.assign(g.size(),-1);
        vector<bool> v(g.size(),false);
        vector<int> ans;
        for(int i=0;i<g.size();i++){
            if(dfs(g,v,i)){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};