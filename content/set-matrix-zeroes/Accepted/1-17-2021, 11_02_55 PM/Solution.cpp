// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto i : col){
            for(int j=0;j<m;j++){
                matrix[j][i]=0;
            }
        }
        for(auto i : row){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
    }
};