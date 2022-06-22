// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int cnt;
    vector<vector<bool>> vis;
    int countServers(vector<vector<int>>& g) {
        int cnt=0;
        int cnt1=0;
        int ans=0;
        int x=0,y=0;
        vis=vector<vector<bool>>(g.size(),vector<bool>(g[0].size(),false));
        for(int i=0;i<g.size();i++){
            cnt=0;
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    cnt++;
                    vis[i][j]=true;
                    x=i;
                    y=j;
                }
            }
            if(cnt>=2){
                ans+=cnt;
            }
            else if(cnt==1){
                vis[x][y]=false;
            }
        }
        for(int i=0;i<g[0].size();i++){
            cnt=cnt1=0;
            for(int j=0;j<g.size();j++){
                if(g[j][i]==1){
                    cnt++;
                    if(vis[j][i]==false){
                        cnt1++;
                    }
                    vis[j][i]=true;
                }
            }
            if(cnt>=2){
                ans+=cnt1;
            }
        }
        return ans;
    }
};