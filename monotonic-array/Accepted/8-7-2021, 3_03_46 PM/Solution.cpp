// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool f1=true;
        bool f2=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                f1=false;
            }
            if(nums[i]<nums[i-1]){
                f2=false;
            }
        }
        return f1|f2;
    }
};