// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int pre=-101;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == pre) continue;
            pre=nums[i];
            nums[cnt]=nums[i];
            cnt++;
        }
        return cnt;
    }
};