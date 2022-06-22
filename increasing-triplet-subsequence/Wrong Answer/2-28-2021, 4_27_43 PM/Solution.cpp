// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int cnt=0;
        int m=nums.size();
        for(int i=1;i<m;i++){
            if(nums[i-1]>nums[i]) cnt=1;
            if(cnt>=3) return true;
            cnt++;
        }
        return false;
    }
};