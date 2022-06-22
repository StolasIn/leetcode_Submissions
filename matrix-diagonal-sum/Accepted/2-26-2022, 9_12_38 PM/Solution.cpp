// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int i = 0,j = 0;
        int m = mat.size();
        while(i<m){
            ans+=mat[i][j];
            i++;
            j++;
        }
        i = m-1,j = 0;
        while(i>=0){
            ans+=mat[i][j];
            i--;
            j++;
        }
        if(m%2==1){
            ans-=mat[m/2][m/2];
        }
        return ans;
    }
};