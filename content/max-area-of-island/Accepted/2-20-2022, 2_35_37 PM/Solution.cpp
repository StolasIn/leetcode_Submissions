// https://leetcode.com/problems/max-area-of-island

struct node{
    int x;
    int y;
};
class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int bfs(vector<vector<int>>& g,vector<vector<bool>>& vis,int x,int y){
        queue<node> q;
        q.push(node{x,y});
        int cnt = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.x<0 || t.y<0 || t.x>=g.size() || t.y>=g[0].size()){
                continue;
            }
            if(vis[t.x][t.y] == true){
                continue;
            }
            vis[t.x][t.y] = true;
            if(g[t.x][t.y]==1){
                cnt++;
                for(int i=0;i<dir.size();i++){
                q.push(node{t.x + dir[i][0] , t.y + dir[i][1]});
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        vector<vector<bool>> vis(g.size(),vector<bool>(g[0].size(),false));
        int m = g.size(),n = g[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1 && vis[i][j]==false){
                    ans = max(ans,bfs(g,vis,i,j));
                }
            }
        }
        return ans;
    }
};