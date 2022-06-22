// https://leetcode.com/problems/jump-game

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);        
    }

    
    bool canJump(vector<int>& nums) {
       
        int goal = nums.size()-1;
        for( int i = nums.size()-2 ; i>= 0 ; i-- ){
            if( nums[i]+ i >= goal ) goal = i;
        }      
        
        return goal == 0;
    }
};