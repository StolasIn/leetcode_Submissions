// https://leetcode.com/problems/jump-game

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);        
    }
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        int now = m-1;
        for(int i=m-2;i>=0;i--){
            if(nums[i] >= now - i){
                now = i;
            }
        }
        return now == 0;
    }
};