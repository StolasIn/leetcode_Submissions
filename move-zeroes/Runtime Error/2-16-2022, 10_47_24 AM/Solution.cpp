// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int next = 0;
        while(nums[next]!=0) next++;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[next]);
                next++;
            }
        }
    }
};