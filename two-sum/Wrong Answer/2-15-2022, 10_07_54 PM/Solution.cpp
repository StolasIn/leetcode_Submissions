// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(r>l){
            if(nums[l] + nums[r] == target){
                return {l,r};
            }
            else if(nums[l] + nums[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};