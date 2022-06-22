// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[0]>target){
            return 0;
        }
        if(nums[nums.size()-1]<target){
            return nums.size();
        }
        while(right>=left){
            int mid = (right+left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                if(mid!=0 && nums[mid-1]<target){
                    return mid-1;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                if(mid!=nums.size()-1 && nums[mid+1]>target){
                    return mid+1;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};