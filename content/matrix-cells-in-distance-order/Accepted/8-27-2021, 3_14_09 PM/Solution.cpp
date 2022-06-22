// https://leetcode.com/problems/matrix-cells-in-distance-order

struct node{
    int x,y;
};
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int r, int c, int rc, int cc) {
        queue<node> q;
        vector<vector<int>> ans;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        q.push(node{rc,cc});
        while(!q.empty()){
            node t = q.front();
            q.pop();
            if(t.x<0 || t.x>=r || t.y<0 || t.y>=c){
                continue;
            }
            if(vis[t.x][t.y]==true) continue;
            ans.emplace_back(vector<int>{t.x,t.y});
            vis[t.x][t.y]=true;
            q.push(node{t.x-1,t.y});
            q.push(node{t.x,t.y-1});
            q.push(node{t.x+1,t.y});
            q.push(node{t.x,t.y+1});
        }
        return ans;
    }
};