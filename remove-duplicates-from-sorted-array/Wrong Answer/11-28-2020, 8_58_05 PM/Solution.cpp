// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]) cnt++;
        }
        return cnt;
    }
};