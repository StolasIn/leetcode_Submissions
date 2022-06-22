// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cmp;
        cmp.assign(heights.begin(),heights.end());
        sort(heights.begin(),heights.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(cmp[i]!=heights[i]){
                ans++;
            }
        }
        return ans;
    }
};