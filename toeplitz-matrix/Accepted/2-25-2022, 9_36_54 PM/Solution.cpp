// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool ist(vector<vector<int>>& mat,int x,int y){
        int m = mat.size();
        int n = mat[0].size();
        int t = mat[x][y];
        while(x<m && y<n){
            if(mat[x][y]!=t){
                return false;
            }
            else{
                x++;
                y++;
            }
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        for(int i=0;i<mat[0].size();i++){
            if(ist(mat,0,i)==false){
                return false;
            }
        }
        for(int i=0;i<mat.size();i++){
            if(ist(mat,i,0)==false){
                return false;
            }
        }
        return true;
    }
};