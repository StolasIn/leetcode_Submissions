// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int l=0;
        int r=nums.size()-1;
        int tar=(l+r+1)/2;
        while(r>l){
            if(nums[tar]<target){
                l=tar;
                if(tar==(l+r+1)/2) break;
                tar=(l+r+1)/2;
            }
            else if(nums[tar]<target){
                r=tar;
                if(tar==(l+r+1)/2) break;
                tar=(l+r+1)/2;
            }
            else{
                break;
            }
        }
        return tar;
    }
};