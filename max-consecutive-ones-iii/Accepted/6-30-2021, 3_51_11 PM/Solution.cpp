// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0;
        int ma=0;
        while(r<nums.size()){
            if(cnt<=k){
                ma=max(ma,r-l);
                if(nums[r]==0){
                    cnt++;
                }
                r++;
            }
            else{
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
        }
        if(cnt<=k){
            ma=max(ma,r-l);
        }
        return ma;
    }
};