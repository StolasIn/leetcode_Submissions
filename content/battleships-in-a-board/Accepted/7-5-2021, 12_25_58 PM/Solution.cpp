// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    void rdfs(vector<vector<char>>& b,int x,int y,int d){
        if(x<0 || x>=b.size() || y<0 || y>=b[0].size()) return;
        if(b[x][y]!='X') return;
        b[x][y]='0';
        switch(d){
            case 0:
                if(x-1>0) rdfs(b,x-1,y,0);
                break;
            case 1:
                if(x+1<b.size()) rdfs(b,x+1,y,1);
                break;
            case 2:
                if(y-1>0) rdfs(b,x,y-1,2);
                break;
            case 3:
                if(y+1<b[0].size()) rdfs(b,x,y+1,3);
                break;
        }
    }
    int countBattleships(vector<vector<char>>& b) {
        int m=b.size();
        int n=b[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]=='X'){
                    b[i][j]='0';
                    if(i-1>0 && b[i-1][j]=='X') rdfs(b,i-1,j,0);
                    else if(i+1<b.size() && b[i+1][j]=='X') rdfs(b,i+1,j,1);
                    else if(j-1>0 && b[i][j-1]=='X') rdfs(b,i,j-1,2);
                    else if(j+1<b[0].size() && b[i][j+1]=='X') rdfs(b,i,j+1,3);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};