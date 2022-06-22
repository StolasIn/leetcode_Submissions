// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& col) {
        vector<vector<int>> ans(2,vector<int>(col.size(),-1));
        int sum=0;
        for(int i=0;i<col.size();i++){
            if(col[i]==2){
                ans[0][i]=ans[1][i]=1;
                u--;
                l--;
            }
            else if(col[i]==0){
                ans[0][i]=ans[1][i]=0;
            }
            else{
                sum++;
            }
        }
        if(sum>l+u) return {};
        for(int i=0;i<col.size();i++){
            if(ans[0][i]==-1){
                if(u>0){
                    ans[0][i]=1;
                    ans[1][i]=0;
                    u--;
                }
                else{
                    ans[0][i]=0;
                    ans[1][i]=1;
                    l--;
                }
            }
            if(u<=0 && l<=0) break;
        }
        return ans;
    }
};