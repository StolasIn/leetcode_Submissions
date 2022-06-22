// https://leetcode.com/problems/image-smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dir[9][2] = {{-1,-1},{-1,0},{-1,1},
                         {0,-1},{0,0},{0,1},
                         {1,-1},{1,0},{1,1}};
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int now = 0;
                int cnt = 0;
                for(int k=0;k<9;k++){
                    if(i+dir[k][0]<0 || j+dir[k][1]<0
                        || i+dir[k][0]>=m || j+dir[k][1]>=n){
                    }
                    else{
                        now+=img[i+dir[k][0]][j+dir[k][1]];
                        cnt++;
                    }
                }
                ans[i][j] = floor(now/cnt);
            }
        }
        return ans;
    }
};