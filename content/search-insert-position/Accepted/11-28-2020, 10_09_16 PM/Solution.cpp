// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int l=0;
        int r=nums.size()-1;
        int tar=(l+r)/2;
        while(r>=l){
            tar=(l+r)/2;
            if(nums[tar]<target){
                l=tar+1;
            }
            else{
                r=tar-1;
            }
        }
        return l;
    }
};