// https://leetcode.com/problems/maximum-difference-between-increasing-elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mi = 1e9;
        int dif = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mi){
                mi = nums[i];
            }
            dif = max(dif,nums[i]-mi);
        }
        return dif==0?-1:dif;
    }
};