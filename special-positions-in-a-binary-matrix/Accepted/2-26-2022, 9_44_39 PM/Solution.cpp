// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        int ans = 0;
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            row[i] = cnt;
        }
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[j][i]==1){
                    cnt++;
                }
            }
            col[i] = cnt;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};