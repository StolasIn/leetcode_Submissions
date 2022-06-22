// https://leetcode.com/problems/word-search

class Solution {
public:
    struct node{
        int x,y;
    };
    int m,n;
    bool has=false;
    void dfs(vector<vector<char>>& board, string& word,int now,int x,int y,vector<vector<bool>> vis){
        if(has) return;
        if(x<0 || x>=m || y<0 || y>=n) return;
        if(word[now]!=board[x][y]) return;
        if(vis[x][y]) return;
        vis[x][y]=true;
        //cout<<word[now]<<" "<<board[x][y]<<" "<<now<<" "<<word.size()<<endl;
        if(now==word.size()-1){
            has=true;
            return;
        }
        dfs(board,word,now+1,x+1,y,vis);
        dfs(board,word,now+1,x,y+1,vis);
        dfs(board,word,now+1,x-1,y,vis);
        dfs(board,word,now+1,x,y-1,vis);
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<node> arr;
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    dfs(board,word,0,i,j,vis);
                }
            }
        }
        /*int y=arr.size();
        for(int i=0;i<y;i++){
            cout<<arr[i].x<<" "<<arr[i].y<<" ";
        }
        cout<<endl;*/
        return has;
    }
};