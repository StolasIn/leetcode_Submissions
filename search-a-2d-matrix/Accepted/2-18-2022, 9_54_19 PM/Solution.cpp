// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int i;
        int l=0,r=mat[0].size()-1;
        for(i=0;i<m;i++){
            if(mat[i][0]<=t && mat[i].back()>=t){
                break;
            }
        }
        if(i==m) return false;
        while(r>=l){
            int mid = (r+l)/2;
            if(mat[i][mid]==t){
                return true;
            }
            else if(mat[i][mid]<t){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;
    }
};