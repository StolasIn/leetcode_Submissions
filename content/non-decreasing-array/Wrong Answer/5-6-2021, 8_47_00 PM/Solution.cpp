// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        int m=nums.size();
        for(int i=1;i<m;i++){
            if(nums[i]<nums[i-1]) cnt++;
        }
        if(cnt>=2) return false;
        return true;
    }
};