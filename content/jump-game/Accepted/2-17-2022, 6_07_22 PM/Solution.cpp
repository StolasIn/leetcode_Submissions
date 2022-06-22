// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int now = nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] >= now - i){
                now = i;
            }
        }
        return now == 0;
    }
};