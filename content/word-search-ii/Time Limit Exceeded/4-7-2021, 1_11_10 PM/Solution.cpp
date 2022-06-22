// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis,string& str,int ind,int x,int y){
        if(ind>=str.size() || x<0 || y<0 || x>=m || y>=n) return false;
        if(vis[x][y]==true) return false;
        if(str[ind]!=board[x][y]){
            return false;
        }
        if(ind==str.size()-1 && str[ind]==board[x][y]) return true;
        vis[x][y]=true;
        bool f=dfs(board,vis,str,ind+1,x+1,y) ||
        dfs(board,vis,str,ind+1,x,y+1) ||
        dfs(board,vis,str,ind+1,x-1,y) ||
        dfs(board,vis,str,ind+1,x,y-1);
        vis[x][y]=false;
        return f;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<string> ans;
        bool flag;
        for(auto i : words){
            flag=false;
            for(int k=0;k<board.size();k++){
                for(int j=0;j<board[0].size();j++){
                    flag=dfs(board,vis,i,0,k,j);
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};