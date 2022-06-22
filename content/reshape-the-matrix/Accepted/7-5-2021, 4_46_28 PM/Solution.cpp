// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& num, int r, int c) {
        if(num.size()*num[0].size()!=r*c) return num;
        vector<vector<int>> ans(r,vector<int>(c));
        vector<int> tmp;
        int cnt=0;
        for(int i=0;i<num.size();i++) tmp.insert(tmp.end(),num[i].begin(),num[i].end());
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=tmp[cnt++];
            }
        }
        return ans;
    }
};