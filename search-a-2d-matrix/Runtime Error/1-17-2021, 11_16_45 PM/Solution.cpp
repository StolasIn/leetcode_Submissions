// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0;
        int right=(m*n-1);
        int mid;
        while(right>left){
            mid=(right+left)/2;
            if(target<matrix[mid%n-1][mid%m-1]){
                right=mid-1;
            }
            else if(target>matrix[mid%n-1][mid%m-1]){
                left=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};