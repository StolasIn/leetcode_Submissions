// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(i==0){
                    g[i][j] = g[i][j-1] + g[i][j];
                }
                else if(j==0){
                    g[i][j] = g[i-1][j] + g[i][j];
                }
                else{
                    g[i][j] = min(g[i-1][j],g[i][j-1]) + g[i][j];
                }
            }
        }
        return g[m-1][n-1];
    }
};