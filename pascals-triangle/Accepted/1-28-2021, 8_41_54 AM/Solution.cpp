// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> ans(num);
        if(num==0) return ans;
        if(num==1){
            ans[0].push_back(1);
            return ans;
        } 
        ans[0].emplace_back(1);
        ans[1].emplace_back(1);
        ans[1].emplace_back(1);
        for(int i=2;i<num;i++){
            ans[i].resize(i+1);
            ans[i][0]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans[i][i]=1;
        }
        return ans;
    }
};