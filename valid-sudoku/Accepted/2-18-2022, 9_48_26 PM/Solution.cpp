// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int dir[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        unordered_set<char> s;
        for(int i : {1,4,7}){
            for(int j : {1,4,7}){
                s.clear();
                for(int k=0;k<9;k++){
                    if(board[i+dir[k][0]][j+dir[k][1]]=='.') continue;
                    if(s.find(board[i+dir[k][0]][j+dir[k][1]])!=s.end()){
                        return false;
                    }
                    s.insert(board[i+dir[k][0]][j+dir[k][1]]);
                }
            }
        }
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(s.find(board[i][j])!=s.end()){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(s.find(board[j][i])!=s.end()){
                    return false;
                }
                s.insert(board[j][i]);
            }
        }
        return true;
    }
};