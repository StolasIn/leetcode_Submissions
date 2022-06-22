// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix.size()));
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                ans[i][m-j-1]=matrix[j][i];
            }
        }
        matrix.clear();
        matrix.assign(ans.begin(),ans.end());
    }
};