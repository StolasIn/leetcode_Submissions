// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int m=nums.size();
        int cnt=0;
        int ma=-1;
        for(int i=1;i<m;i++){
            ma=max(ma,cnt);
            cnt++;
            if(nums[i]<=nums[i-1]) cnt=0;
        }
        return ma+1;
    }
};