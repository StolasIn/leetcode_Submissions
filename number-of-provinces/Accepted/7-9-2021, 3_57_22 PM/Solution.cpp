// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    vector<bool> vis;
    int m;
    void dfs(vector<vector<int>>& is,int now){
        vis[now]=true;
        for(int i=0;i<m;i++){
            if(i!=now && is[now][i]==1 && vis[i]==false){
                dfs(is,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        m=is.size();
        int cnt=0;
        vis.assign(m,false);
        for(int i=0;i<m;i++){
            if(vis[i]==false){
                cnt++;
                dfs(is,i);
            }
        }
        return cnt;
    }
};