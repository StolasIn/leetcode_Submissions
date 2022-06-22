// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mi = 1e9;
        int now = 0;
        for(int i=0;i<nums.size();i++){
            now+=nums[i];
            mi = min(mi,now);
        }
        if(mi<0){
            return abs(mi)+1;
        }
        return 1;
    }
};