// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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