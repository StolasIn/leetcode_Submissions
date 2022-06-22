// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int m=nums.size();
        int sum=0,l=0,ans=INT_MAX;
        for(int r=0;r<m;r++){
            sum+=nums[r];
            while(sum>target){
                sum-=nums[l++];
            }
            if(sum==target){
                ans=min(ans,r-l+1);
            }
        }
        return ans==INT_MAX? 0 : ans;
    }
};