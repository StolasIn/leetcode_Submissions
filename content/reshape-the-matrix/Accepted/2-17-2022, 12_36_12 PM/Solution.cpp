// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> flat;
        vector<vector<int>> ans(r,vector<int>(c));
        int cnt = 0;
        if((m*n != r*c) || (m==r && n==c)){
            return mat;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flat.emplace_back(mat[i][j]);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j] = flat[cnt++];
            }
        }
        return ans;
    }
};