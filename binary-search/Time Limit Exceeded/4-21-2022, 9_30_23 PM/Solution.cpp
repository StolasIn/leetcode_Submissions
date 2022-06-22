// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(right>=left){
            int mid = (right+left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid;
            }
        }
        return -1;
    }
};