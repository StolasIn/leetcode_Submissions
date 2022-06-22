// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int cnt = 1;
        int pre = -1;
        int ans = -1;
        for(int i=0;i<e.size();i++){
            if(pre!=e[i][0]){
                pre = e[i][0];
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt==0){
                ans = e[i][0];
            }
            if(pre!=e[i][1]){
                pre = e[i][1];
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt==0){
                ans = e[i][1];
            }
        }
        return ans;
    }
};