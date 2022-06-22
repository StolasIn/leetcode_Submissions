// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt;
        int n=nums.size();
        for(cnt=0;cnt<n;cnt++){
            if(nums[cnt]==target) return cnt;
        }
        return -1;
    }
};