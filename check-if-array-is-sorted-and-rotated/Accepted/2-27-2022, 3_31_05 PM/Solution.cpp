// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int m = nums.size();
        if(nums[0]>=nums[m-1]){
            int i;
            for(i=0;i<m-1;i++){
                if(nums[i]>nums[i+1]){
                    break;
                }
            }
            i++;
            for(;i<m-1;i++){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
        }
        else{
            for(int i=0;i<m-1;i++){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};