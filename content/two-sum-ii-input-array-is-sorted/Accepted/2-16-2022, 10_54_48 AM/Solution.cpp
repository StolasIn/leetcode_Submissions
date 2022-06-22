// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(r>l){
            if(nums[l] + nums[r] == target){
                return {l+1,r+1};
            }
            else if(nums[l] + nums[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};