// https://leetcode.com/problems/game-of-life

struct cell{
    int state,live,dead;
};
class Solution {
public:
    cell counts(vector<vector<cell>>& c,int x,int y){
        int l=0,d=0;
        for(int i=x-1;i<x+2;i++){
            for(int j=y-1;j<y+2;j++){
                if(c[i][j].state==0){
                    d++;
                }
                else if(c[i][j].state==1){
                    l++;
                }
            }
        }
        if(c[x][y].state==1){
            l--;
        }
        else{
            d--;
        }
        return cell{c[x][y].state,l,d};
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<cell>> b(m+2,vector<cell>(n+2,cell{-1,0,0}));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                b[i][j].state=board[i-1][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                b[i][j]=counts(b,i,j);
            }
        }
        /*for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cout<<b[i][j].dead<<" ";
            }
            cout<<endl;
        }*/
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(b[i][j].live<2 && b[i][j].state==1){
                    board[i-1][j-1]=0;
                }
                else if((b[i][j].live==2 || b[i][j].live==3) && b[i][j].state==1){
                }
                else if(b[i][j].live>3 && b[i][j].state==1){
                    board[i-1][j-1]=0;
                }
                else if(b[i][j].live==3 && b[i][j].state==0){
                    board[i-1][j-1]=1;
                }
            }
        }
    }
};