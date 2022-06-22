// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        if(o.size()!=m*n){
            return {};
        }
        vector<vector<int>> ans(m,vector<int>(n));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = o[cnt++];
            }
        }
        return ans;
    }
};