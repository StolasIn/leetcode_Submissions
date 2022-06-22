// https://leetcode.com/problems/path-with-minimum-effort

struct node{
    int x,y,d;
    bool operator<(const node& a) const{
        return d>a.d;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        priority_queue<node> pq;
        pq.push(node{0,0,0});
        while(!pq.empty()){
            node t = pq.top();
            pq.pop();
            if(vis[t.x][t.y]==true){
                continue;
            }
            vis[t.x][t.y] = true;
            for(int i=0;i<4;i++){
                int x =  t.x + dir[i][0];
                int y =  t.y + dir[i][1];
                if(x<0 || x>=m || y<0 || y>=n){
                    continue;
                }
                if(dis[x][y]>abs(h[x][y]-h[t.x][t.y])){
                    dis[x][y]=abs(h[x][y]-h[t.x][t.y]);
                    pq.push(node{x,y,dis[x][y]});
                }
            }
        }
        return dis[m-1][n-1];
    }
};