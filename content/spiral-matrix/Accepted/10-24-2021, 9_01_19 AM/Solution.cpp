// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> ans;
        int m = ma.size();
        int n = ma[0].size();
        int l=0,r=n-1,t=0,b=m-1;
        int now=0;
        while(l<=r && t<=b){
            if(now==0){
                for(int i=l;i<=r;i++){
                    ans.emplace_back(ma[t][i]);
                }
                t++;
            }
            else if(now==1){
                for(int i=t;i<=b;i++){
                    ans.emplace_back(ma[i][r]);
                }
                r--;
            }
            else if(now==2){
                for(int i=r;i>=l;i--){
                    ans.emplace_back(ma[b][i]);
                }
                b--;
            }
            else{
                for(int i=b;i>=t;i--){
                    ans.emplace_back(ma[i][l]);
                }
                l++;
            }
            now=(now+1)%4;
        }
        return ans;
    }
};