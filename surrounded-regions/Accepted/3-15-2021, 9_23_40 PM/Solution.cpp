// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    int m,n;
    struct node{
        int x,y;  
    };
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int x,int y){
        if(x<0 || x>=m || y<0 || y>=n || vis[x][y]==true || board[x][y]=='X') return;
        vis[x][y]=true;
        dfs(board,vis,x-1,y);
        dfs(board,vis,x,y-1);
        dfs(board,vis,x+1,y);
        dfs(board,vis,x,y+1);
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
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                g.emplace_back(node{0,i});
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                g.emplace_back(node{i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O'){
                g.emplace_back(node{m-1,i});
            }
        }
        for(auto i : g){
            //cout<<i.x<<" "<<i.y<<endl;
            dfs(board,vis,i.x,i.y);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==true){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};