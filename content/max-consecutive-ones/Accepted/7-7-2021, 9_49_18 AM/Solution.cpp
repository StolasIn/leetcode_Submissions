// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ze=0;
        int l=0,r=0;
        nums.emplace_back(0);
        int m=nums.size();
        int ma=0;
        while(r<m){
            if(ze==0){
                ma=max(ma,r-l);
                if(nums[r]==0){
                    ze++;
                }
                r++;
            }
            else{
                if(nums[l]==0){
                    ze--;
                }
                l++;
            }
        }
        return ma;
    }
};