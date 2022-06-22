// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ma1=-1;
        int ma2=-1;
        int ind;
        int m=nums.size();
        for(int i=0;i<m;i++){
            if(nums[i]>ma1){
                ma1=nums[i];
                ind=i;
            }
        }
        for(int i=0;i<m;i++){
            if(nums[i]!=ma1){
                ma2=max(ma2,nums[i]);
            }
        }
        return ma1>=2*ma2? ind : -1;
    }
};