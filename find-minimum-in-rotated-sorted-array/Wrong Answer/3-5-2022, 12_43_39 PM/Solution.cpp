// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = nums.size();
        int l = 0,r = m-1;
        if (nums[r] > nums[0]) {
            return nums[0];
        }
        while(r>=l){
            int mid = (r-l)/2 + l;
            if(mid+1<m && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(mid-1>0 && nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            else if(nums[l]<nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
};