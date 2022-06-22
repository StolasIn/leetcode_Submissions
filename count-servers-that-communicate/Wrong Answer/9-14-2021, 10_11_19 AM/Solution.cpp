// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int cnt;
    vector<vector<bool>> vis;
    int connect(vector<vector<int>>& g,int x,int y){
        if(x<0 || x>=g.size() || y<0 || y>=g[0].size()){
            return 0;
        }
        if(g[x][y]==0 || vis[x][y]==true){
            return 0;
        }
        vis[x][y]=true;
        
        return 
        connect(g,x-1,y)+
        connect(g,x,y-1)+
        connect(g,x+1,y)+
        connect(g,x,y+1)+1;
    }
    int countServers(vector<vector<int>>& g) {
        cnt=0;
        vis=vector<vector<bool>>(g.size(),vector<bool>(g[0].size(),false));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    int t = connect(g,i,j);
                    if(t>=2) cnt+=t;
                }
            }
        }
        return cnt;
    }
};