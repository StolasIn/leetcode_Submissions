// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int now = 0;
        int ans = 0;
        int ans1 = -1e9;
        for(int i=0;i<nums.size();i++){
            now+=nums[i];
            ans = max(ans,now);
            ans1 = max(ans1,nums[i]);
            if(now<0){
                now=0;
            }
        }
        return max(ans,ans1);
    }
};