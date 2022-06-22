// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    void dfs(vector<vector<int>>& g,int x,vector<bool>& vis){
        if(vis[x]) return;
        vis[x]=true;
        for(auto i : g[x]){
            dfs(g,i,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        dfs(rooms,0,vis);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
};