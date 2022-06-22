// https://leetcode.com/problems/queens-that-can-attack-the-king

class Solution {
public:
    vector<vector<int>> dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<int>> ans;
    unordered_map<int,unordered_map<int,bool>> map;
    void dfs(int x,int y,int d){
        if(x<0 || x>=8 || y<0 || y>=8){
            return;
        }
        if(map[x][y]==true){
            ans.emplace_back(vector<int>{x,y});
            return;
        }
        dfs(x+dir[d][0],y+dir[d][1],d);
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        for(auto& i : queens){
            map[i[0]][i[1]]=true;
        }
        for(int i=0;i<dir.size();i++){
            dfs(king[0],king[1],i);
        }
        return ans;
    }
};