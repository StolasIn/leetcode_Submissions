// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        pre.assign(matrix.begin(),matrix.end());
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                }
                else if(i==0){
                    pre[i][j] += pre[i][j-1];
                }
                else if(j==0){
                    pre[i][j] += pre[i-1][j];
                }
                else{
                    pre[i][j] += pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==row2 && col1==col2) return pre[row1][col1];
        return pre[row2][col2]-pre[row2][col1-1]-pre[row1-1][col2]+pre[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */