// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int zeros=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeros++;
            else{
                ans.push_back(nums[i]);
            }
        }
        nums.clear();
        nums.assign(ans.begin(),ans.end());
        for(;zeros>0;zeros--){
            nums.push_back(0);
        }
    }
};