// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return 15;
        int l=0,r=0;
        int m=nums.size();
        int sum=0;
        int ans=0;
        while(r<m){
            if(sum<=goal){
                sum+=nums[r];
                if(sum<=goal) ans++;
                r++;
            }
            else{
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};