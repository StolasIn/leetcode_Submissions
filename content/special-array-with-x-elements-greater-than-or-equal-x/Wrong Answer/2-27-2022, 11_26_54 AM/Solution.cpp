// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size();
        int ans = 0;
        for(int i=0;i<m;i++){
            if(m-i<=nums[i]){
                return m-i;
            }
        }
        return -1;
    }
};