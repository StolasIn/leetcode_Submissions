// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    int m,n;
    struct node{
        int x,y;  
    };
    void dfs(vector<vector<char>>& board,vector<vector<bool>> vis,int x,int y){
        if(vis[x][y]==true || x<0 || x>=m || y<0 || y>=n) return;
        vis[x][y]=true;
        dfs(board,vis,x-1,y);
        dfs(board,vis,x,y-1);
        dfs(board,vis,x+1,y);
        dfs(board,vis,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<node> g;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                g.emplace_back(node{i,0});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                g.emplace_back(node{0,i});
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][m-1]=='O'){
                g.emplace_back(node{i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                g.emplace_back(node{n-1,i});
            }
        }
        for(auto i : g){
            dfs(board,vis,i.x,i.y);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==true){
                    board[i][j]='O';
                }
            }
        }
    }
};