// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int m = nums.size();
        int now = 0;
        int ans = -1e9;
        for(int i=0;i<nums.size();i++){
            now+=nums[i];
            ans = max(ans,now);
            if(now<0){
                now=0;
            }
        }
        if(ans<0){
            return ans;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        int l = m/2-1,r=m/2+1;
        ans = max(ans,nums[l]+nums[r]);
        while(l>0){
            ans = max(ans,nums[l-1]+nums[r]);
            ans = max(ans,nums[l]+nums[r+1]);
            l--;
            r++;
        }
        return ans;
    }
};