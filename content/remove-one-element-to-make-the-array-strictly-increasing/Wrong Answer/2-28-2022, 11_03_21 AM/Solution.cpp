// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;
        if(nums[0]>=nums[1]){
            cnt++;
        }
        int m = nums.size();
        nums.emplace_back(1e9);
        for(int i=1;i<m-1;i++){
            if(nums[i]>=nums[i+1]){
                cnt++;
                if(nums[i+2]>nums[i]){
                    nums[i+1] = nums[i+2]-1;
                }
                else{
                    nums[i+1] = nums[i-1]+1;
                }
            }
            if(cnt>=2){
                return false;
            }
        }
        return true;
    }
};