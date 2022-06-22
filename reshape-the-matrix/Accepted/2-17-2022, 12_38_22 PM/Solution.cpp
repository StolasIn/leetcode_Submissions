// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int x=0,y=0;
        vector<vector<int>> ans(r,vector<int>(c));
        int cnt = 0;
        if((m*n != r*c) || (m==r && n==c)){
            return mat;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j] = mat[x][y];
                y++;
                if(y>=n){
                    x++;
                    y=0;
                }
            }
        }
        return ans;
    }
};