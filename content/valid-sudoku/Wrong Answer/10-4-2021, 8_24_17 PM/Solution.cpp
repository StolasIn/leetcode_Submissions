// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){
                    if(s.find(board[i][j])!=s.end()){
                        return false;
                    }
                    else{
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(isdigit(board[j][i])){
                    if(s.find(board[j][i])!=s.end()){
                        return false;
                    }
                    else{
                        s.insert(board[j][i]);
                    }
                }
            }
        }
        return true;
    }
};