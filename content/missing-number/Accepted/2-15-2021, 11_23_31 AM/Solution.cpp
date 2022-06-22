// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m=nums.size();
        int a=m;
        for(int i=0;i<m;i++){
            a^=i^nums[i];
        }
        return a;
    }
};