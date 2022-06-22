// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int cand, int num) {
        vector<int> ans(num,0);
        for(int i=0;cand>0;i++){
            if(cand>i+1){
                ans[i%num]=i+1;
            }
            else{
                ans[i%num]=cand;
            }
            cand-=(i+1);
        }
        return ans;
    }
};