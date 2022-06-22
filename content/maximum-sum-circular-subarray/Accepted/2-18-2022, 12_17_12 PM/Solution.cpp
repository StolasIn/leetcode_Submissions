// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int m = nums.size();
        int now1 = 0;
        int now2 = 0;
        int ans1 = -1e9;
        int ans2 = 1e9;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            now1+=nums[i];
            ans1 = max(ans1,now1);
            if(now1<0){
                now1=0;
            }
            now2+=nums[i];
            ans2 = min(ans2,now2);
            if(now2>0){
                now2=0;
            }
            total += nums[i];
        }
        return ans1>0 ? max(ans1,total-ans2) : ans1;
    }
};