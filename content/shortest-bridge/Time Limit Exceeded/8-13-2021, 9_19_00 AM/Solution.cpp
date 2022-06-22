// https://leetcode.com/problems/shortest-bridge

struct node{
    int x,y,d;
};
class Solution {
public:
    vector<vector<bool>> vis;
    vector<node> v;
    int mi;
    void connect_comp(vector<vector<int>>& g,int r,int c){
        if(r<0 || r>=g.size() || c<0 || c>=g[0].size()){
            return;
        }
        if(g[r][c]==0 || vis[r][c]==true) return;
        v.emplace_back(node{r,c,0});
        vis[r][c]=true;
        connect_comp(g,r+1,c);
        connect_comp(g,r,c+1);
        connect_comp(g,r-1,c);
        connect_comp(g,r,c-1);
    }
    int bfs(vector<vector<int>>& g,int r,int c){
        queue<node> q;
        q.push(node{r,c,0});
        while(!q.empty()){
            node t = q.front();
            q.pop();
            if(t.x<0 || t.x>=g.size() || t.y<0 || t.y>=g[0].size()) continue;
            if(g[t.x][t.y]==1 && vis[t.x][t.y]==false) return t.d;
            if(t.d>=mi) return 1e9;
            q.push(node{t.x+1,t.y,t.d+1});
            q.push(node{t.x,t.y+1,t.d+1});
            q.push(node{t.x-1,t.y,t.d+1});
            q.push(node{t.x,t.y-1,t.d+1});
        }
        return 1e9;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vis=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),false));
        bool flag=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    connect_comp(grid,i,j);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        mi=1e9;
        for(auto i : v){
            mi=min(mi,bfs(grid,i.x,i.y));
        }
        return mi-1;
    }
};