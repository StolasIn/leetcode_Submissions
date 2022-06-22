// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int now = 0,cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                now = nums[i];
                cnt = 1;
            }
            else{
                cnt += (now==nums[i] ? 1 : -1);
            }
        }
        return now;
    }
};