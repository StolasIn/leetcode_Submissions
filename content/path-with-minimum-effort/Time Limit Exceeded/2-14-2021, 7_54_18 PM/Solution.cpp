// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int ma=-INT_MAX;
    int ans=INT_MAX;
    void dfs(vector<vector<int>>& h,vector<vector<bool>>& vis,int x,int y,int dif,int ma){
        // cout<<x<<" "<<y<<" "<<dif<<endl;
        if(x==h.size()-1 && y==h[0].size()-1){
            ma=max(ma,abs(h[x][y]-dif));
            ans=min(ans,ma);
            return;
        }
        if(x<0 || x>=h.size() || y<0 || y>=h[0].size()) return;
        if(vis[x][y]==true) return;
        vis[x][y]=true;
        ma=max(ma,abs(h[x][y]-dif));
        dfs(h,vis,x-1,y,h[x][y],ma);
        dfs(h,vis,x,y-1,h[x][y],ma);
        dfs(h,vis,x+1,y,h[x][y],ma);
        dfs(h,vis,x,y+1,h[x][y],ma);
        vis[x][y]=false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<bool>> vis(heights.size(),vector<bool>(heights[0].size(),false));
        dfs(heights,vis,0,0,heights[0][0],0);
        return ans;
    }
};